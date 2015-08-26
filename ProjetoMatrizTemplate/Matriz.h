#ifndef MATRIZ_H
#define MATRIZ_H
#include <QString>

namespace TP2{//inicio
template <class tipo>

class Matriz
{
private:
    int quantidadeDeColunas;
    int quantidadeDeLinhas;
    tipo *ptMatriz;
public:
    Matriz(int qLinhas, int qColunas);
    ~Matriz(){if(ptMatriz) delete[] ptMatriz;}

    int getQuantidadeDeLinhas()const {return quantidadeDeLinhas;}
    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}

    void setElemento(tipo elemento, int linha, int coluna)const;
    tipo getElemento(int linha, int coluna)const;

    QString getMatriz()const;
    Matriz<tipo>* matrizTransp()const;

    bool matrizTringSuperior()const;
    bool matrizIdentidade()const;
    bool matrizTriangInferior()const;
    bool matrizSimetrica()const;

    Matriz<tipo>* operator +(Matriz<tipo> const * const mat)const;/* o parametro está em ponteiro pois matA e matB é ponteiro, matC = matA+matB; matC=matA.adicionar(matB)
o parâmetro é um constante para uma constante, onde ele vai poder somente olhar o objeto*/


/*
* = pra onde aponta
& = ele pega o endereço da variavel


ponteiro para uma constante = ele aponta para várias mas não pode modificar para quem ele aponta
ponteiro constante = não esquecer de inicializar ele, ele só aponta para um lugar e não pode ser alterado para quem ele aponta, mas ele pode alterar o valor de quem ele aponta
ponteiro constante para uma constante = ele só pode ver o objeto, mas não pode deixar de apontar o objeto e nem alterar o valor do objeto que ele aponta
*/

    Matriz<tipo>* operator *(Matriz<tipo> const * const mat)const;
    Matriz<tipo>* operator -(Matriz<tipo> const * const mat)const;
    bool operator ==(Matriz<tipo> const * const mat)const;
    bool operator !=(Matriz<tipo> const * const mat)const;
    Matriz<tipo>* multiplicarK(int n);
    Matriz<tipo>* potencia(int n)const;

    bool ortogonal()const;
    bool permutacao()const;
};

template <class tipo>
Matriz<tipo>::Matriz(int qLinhas, int qColunas):
    quantidadeDeColunas(0),
    quantidadeDeLinhas(0),
    ptMatriz(0)
{
    if(qLinhas <= 0) throw QString("A quantidade de linhas tem que ser maior que zero");
    if(qColunas <= 0) throw QString("A quantidade de colunas tem que ser maior que zero");
    try{
        ptMatriz = new tipo[qLinhas*qColunas];
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }
    quantidadeDeColunas = qColunas;
    quantidadeDeLinhas = qLinhas;
}

template <class tipo>
void Matriz<tipo>::setElemento(tipo elemento, int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas) throw QString("Linhas fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas) throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento; // cálculo de posição
}

template <class tipo>
tipo Matriz<tipo>::getElemento(int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas) throw QString("Linhas fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas) throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

template <class tipo>
QString Matriz<tipo>::getMatriz()const{
    QString saida = "";
    for(int l=0; l<  getQuantidadeDeLinhas();l++){
        for(int c=0; c < getQuantidadeDeColunas(); c++){
            saida+= QString::number(getElemento(l,c));
            saida+= " ";
        }
        saida += "\n";
    }
    return saida;
}

template <class tipo>
Matriz<tipo>* Matriz<tipo>::operator +(Matriz<tipo> const * const mat)const{ //CERTO
    if(this->getQuantidadeDeLinhas() != mat->getQuantidadeDeLinhas() ||
       this->getQuantidadeDeColunas() != mat->getQuantidadeDeColunas())
        throw QString ("Não pode ser adicionadas matrizes de tamanhos diferentes");
    try{
        Matriz<tipo> *aux= new Matriz<tipo>(this->getQuantidadeDeLinhas(),this->getQuantidadeDeColunas());
        for(int linha = 0; linha<this->getQuantidadeDeLinhas();linha++)
            for(int coluna = 0;coluna<this->getQuantidadeDeColunas();coluna++){
                tipo valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        return aux;

    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao criada nao podemos adicionar as matrizes");
    }
}

template <class tipo>
Matriz<tipo>* Matriz<tipo>::operator -(Matriz<tipo> const * const mat)const{ //CERTO
    if(this->getQuantidadeDeLinhas() != mat->getQuantidadeDeLinhas() ||  this->getQuantidadeDeColunas() != mat->getQuantidadeDeColunas())
        throw QString ("Não pode ser subtraidas matrizes de tamanhos diferentes");
    try{
        Matriz<tipo> *aux= new Matriz<tipo>(this->getQuantidadeDeLinhas(),this->getQuantidadeDeColunas());
        for(int linha = 0; linha<this->getQuantidadeDeLinhas();linha++)
            for(int coluna = 0;coluna<this->getQuantidadeDeColunas();coluna++){
                tipo valor = this->getElemento(linha,coluna) - mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        return aux;

    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao criada nao podemos subtrair as matrizes");
    }
}

template <class tipo>
Matriz<tipo>* Matriz<tipo>::operator *(Matriz<tipo> const * const mat)const{ //CERTO
    if(this->getQuantidadeDeColunas()  != mat->getQuantidadeDeLinhas() )throw QString("Nao e possivel fazer a multiplicacao das matrizes");
    try{
        Matriz<tipo> *aux = new Matriz<tipo>(this->getQuantidadeDeLinhas(), mat->getQuantidadeDeColunas());
        int a=0,b;
        for(int i=0; i<this->getQuantidadeDeLinhas(); i++){
            b=0;
            for(int j=0; j<mat->getQuantidadeDeColunas(); j++){
                tipo valor=0;
                for (int k=0;k<this->getQuantidadeDeColunas();k++){
                    valor += this->getElemento(i,k)*mat->getElemento(k,j);
                }
                aux->setElemento(valor,a,b++);
            }
            a++;
        }
        return aux;
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos multiplicar as matrizes");
    }
}

template <class tipo>
bool Matriz<tipo>::operator ==(Matriz<tipo> const * const mat)const{ //CERTO
   if(this->getQuantidadeDeLinhas() != mat->getQuantidadeDeLinhas() ||  this->getQuantidadeDeColunas() != mat->getQuantidadeDeColunas())
       return false;
    if(this->getMatriz() == mat->getMatriz())
        return true;
    return false;
}

template <class tipo>
bool Matriz<tipo>::operator !=(Matriz const * const mat)const{ //CERTO
   if(this->getQuantidadeDeLinhas() != mat->getQuantidadeDeLinhas() ||  this->getQuantidadeDeColunas() != mat->getQuantidadeDeColunas())
       return false;
    if(this->getMatriz() != mat->getMatriz())
        return true;
    return false;
}

template <class tipo>
Matriz<tipo>* Matriz<tipo>::matrizTransp()const{ //CERTO
    try{
        Matriz<tipo> *aux = new Matriz<tipo>(this->getQuantidadeDeColunas(),this->getQuantidadeDeLinhas());
        for(int i=0;i<getQuantidadeDeLinhas();i++){
            for(int j =0;j<getQuantidadeDeColunas();j++){
                tipo valor=this->getElemento(i,j);
                aux->setElemento(valor,j,i);
            }
        }
        return aux;
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }
}

template <class tipo>
bool Matriz<tipo>::matrizTringSuperior()const{ //CERTO
    if(this->getQuantidadeDeColunas() != this->getQuantidadeDeLinhas()) return false;
    for (int i=0; i < getQuantidadeDeLinhas(); i++){
        for (int j=0; (j<i) ;j++){
            if (getElemento(i,j) != 0)
                return false;
        }
    }
        return true;
}

template <class tipo>
bool Matriz<tipo>::matrizIdentidade()const{ //CERTO
    if(this->getQuantidadeDeColunas() != this->getQuantidadeDeLinhas()) return false;
    for(int i=0;i<getQuantidadeDeLinhas();i++){
            for(int j =0;j<getQuantidadeDeColunas();j++){
                if((i==j) && (getElemento(i,j) != 1))
                   return false;
                else if((i != j) && (getElemento(i,j) != 0))
                   return false;
            }
        }
        return true;
}

template <class tipo>
bool Matriz<tipo>::matrizTriangInferior()const{ //CERTO
    if(this->getQuantidadeDeColunas() != this->getQuantidadeDeLinhas()) return false;
    for (int i=0; i < getQuantidadeDeLinhas(); i++){
        for (int j=(i+1); j < getQuantidadeDeColunas();j++){
            if (getElemento(i,j) != 0)
                return false;
        }
    }
        return true;

}

template <class tipo>
bool Matriz<tipo>::matrizSimetrica()const{ //CERTO
    if(this->getQuantidadeDeColunas() != this->getQuantidadeDeLinhas()) return false;
    for(int i=0;i<getQuantidadeDeLinhas();i++){
        for(int j =0;j<getQuantidadeDeColunas();j++){
            if(getElemento(i,j) != getElemento(j,i))
                return false;
        }
    }
    return true;
}

template <class tipo>
bool Matriz<tipo>::ortogonal()const{ //CERTO
    try{
    if(this->getQuantidadeDeColunas() != this->getQuantidadeDeLinhas()) return false;
    Matriz<tipo> *aux = new Matriz<tipo>(this->getQuantidadeDeLinhas(), this->getQuantidadeDeColunas());
    aux = (*this)*this->matrizTransp();
    if(aux->matrizIdentidade() == true){
        return true;
        delete aux;
    }
    else{
        return false;
        delete aux;
    }
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
}
}

template <class tipo>
bool Matriz<tipo>::permutacao()const{ //CERTO
    tipo soma=0;
    for(int linha = 0; linha<this->getQuantidadeDeLinhas();linha++){
        for(int coluna = 0;coluna<this->getQuantidadeDeColunas();coluna++){
            if((getElemento(linha,coluna) != 0) && (getElemento(linha,coluna) != 1))
                return false;
            soma = soma + getElemento(linha,coluna);
        }
        if(soma != 1)
            return false;
        soma=0;
    }
    soma=0;
    for(int coluna = 0;coluna<this->getQuantidadeDeColunas();coluna++){
        for(int linha = 0; linha<this->getQuantidadeDeLinhas();linha++)
            soma = soma +getElemento(linha,coluna);
        if(soma != 1)
            return false;
        soma=0;
    }
    return true;
}

template <class tipo>
Matriz<tipo>* Matriz<tipo>::multiplicarK(int n){ //CERTO
    try{
        Matriz<tipo> *aux= new Matriz<tipo>(this->getQuantidadeDeLinhas(),this->getQuantidadeDeColunas());
        for(int linha = 0; linha<this->getQuantidadeDeLinhas();linha++)
            for(int coluna = 0;coluna<this->getQuantidadeDeColunas();coluna++){
                tipo valor = getElemento(linha,coluna)*n;
                aux->setElemento(valor,linha,coluna);
            }
        return aux;
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao criada nao podemos multiplicar por k as matrizes");
    }
}

template <class tipo>
Matriz<tipo>* Matriz<tipo>::potencia(int n)const{ //CERTO
    try{
        Matriz<tipo> *aux = new Matriz<tipo>(this->getQuantidadeDeLinhas(), this->getQuantidadeDeColunas());        
        if(n==0){
            for(int linha = 0; linha<this->getQuantidadeDeLinhas();linha++)
                for(int coluna = 0;coluna<this->getQuantidadeDeColunas();coluna++){
                    if(linha == coluna) aux->setElemento(1,linha,coluna);
                    if(linha != coluna) aux->setElemento(0,linha,coluna);
                }
            return aux;
        }
        for(int linha = 0; linha<this->getQuantidadeDeLinhas();linha++)
            for(int coluna = 0;coluna<this->getQuantidadeDeColunas();coluna++){
                aux->setElemento(this->getElemento(linha,coluna),linha,coluna);
            }
        while(n>1){
           Matriz<tipo> *aux2 =((*this) * (aux));
            delete aux;
            aux = aux2;
            n--;
        }
        return aux;
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos multiplicar as matrizes");
    }
}


} // fim
#endif // MATRIZ_H
