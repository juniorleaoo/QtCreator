#include "Matriz.h"

namespace TP2{//inicio


Matriz::Matriz(int qLinhas, int qColunas):
    quantidadeDeLinhas(0),
    quantidadeDeColunas(0),
    ptMatriz(0)
{
    if(qLinhas <= 0) throw QString("A quantidade de linhas tem que ser maior que zero");
    if(qColunas <= 0) throw QString("A quantidade de colunas tem que ser maior que zero");
    try{
        ptMatriz = new int[qLinhas*qColunas];
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }
    quantidadeDeColunas = qColunas;
    quantidadeDeLinhas = qLinhas;
}

void Matriz::setElemento(int elemento, int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas) throw QString("Linhas fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas) throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento; // cálculo de posição
/*
                            CÁLCULO DE POSIÇÃO
  é a quantidade de linhas que é passado pelo parâmetro vezes a quantidade de linhas criado mais a quantidade de colunas passado por
  parâmetro

  *(ptMatriz+pos) = elemento
  partindo do inicio da matriz, desloque a quantidade de casas da "pos"
  o ptMatriz tem o endereço do inicio da matriz, ele vai pegar o endereço e somar com a quantidade de pos vezes 2 (caso seja int)


*/
}

int Matriz::getElemento(int linha, int coluna)const{
    if(linha<0 || linha>=quantidadeDeLinhas) throw QString("Linhas fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas) throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

QString Matriz::getMatriz()const{
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

Matriz* Matriz::operator +(Matriz const * const mat)const{ //CERTO
    if(quantidadeDeLinhas != mat->getQuantidadeDeLinhas() ||
       quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString ("Não pode ser adicionadas matrizes de tamanhos diferentes");
    try{
        Matriz *aux= new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha = 0; linha<quantidadeDeLinhas;linha++)
            for(int coluna = 0;coluna<quantidadeDeColunas;coluna++){
                int valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        return aux;

    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao criada nao podemos adicionar as matrizes");
    }
}

Matriz* Matriz::operator *(Matriz const * const mat)const{ //CERTO
    if( quantidadeDeColunas  != mat->getQuantidadeDeLinhas() )throw QString("Nao e possivel fazer a multiplicacao das matrizes");
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas, mat->getQuantidadeDeColunas());
        int a=0,b;
        for(int i=0; i<quantidadeDeLinhas; i++){
            b=0;
            for(int j=0; j<mat->getQuantidadeDeColunas(); j++){
                int valor=0;
                for (int k=0;k<quantidadeDeColunas;k++){
                    valor += this->getElemento(i,k)*mat->getElemento(k,j);
                }
                aux->setElemento(valor,a,b++);
            }
            a++;
        }
        return aux;
    }
    catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }
    catch(QString &erro){
        throw QString("Matriz auxiliar nao Criada nao podemos adicionar as matrizes");
    }
}

Matriz* Matriz::operator -(Matriz const * const mat)const{ //CERTO
    if(quantidadeDeLinhas != mat->getQuantidadeDeLinhas() ||  quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString ("Não pode ser subtraidas matrizes de tamanhos diferentes");
    try{
        Matriz *aux= new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha = 0; linha<quantidadeDeLinhas;linha++)
            for(int coluna = 0;coluna<quantidadeDeColunas;coluna++){
                int valor = this->getElemento(linha,coluna) - mat->getElemento(linha,coluna);
                aux->setElemento(valor,linha,coluna);
            }
        return aux;

    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao criada nao podemos adicionar as matrizes");
    }
}

bool Matriz::operator ==(Matriz const * const mat)const{ //CERTO
    if(quantidadeDeLinhas != mat->getQuantidadeDeLinhas() ||  quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString ("Matrizes de tamanhos diferentes");

    if(this->getMatriz() == mat->getMatriz())
        return true;
    return false;
}

bool Matriz::operator !=(Matriz const * const mat)const{ //CERTO

    if(quantidadeDeLinhas != mat->getQuantidadeDeLinhas() ||  quantidadeDeColunas != mat->getQuantidadeDeColunas())
        throw QString ("Matrizes de tamanhos diferentes");
    if(this->getMatriz() != mat->getMatriz())
        return true;
    return false;
}

Matriz* Matriz::matrizTransp()const{ //CERTO
    Matriz *aux = new Matriz(quantidadeDeColunas,quantidadeDeLinhas);
    for(int i=0;i<getQuantidadeDeLinhas();i++){
            for(int j =0;j<getQuantidadeDeColunas();j++){
                int valor=this->getElemento(i,j);
                aux->setElemento(valor,j,i);

            }
        }
    return aux;
}

bool Matriz::matrizTringSuperior()const{ //CERTO
    int p=1;
    for (int i=0; i < getQuantidadeDeLinhas(); i++){
        for (int j=0; (j<i) ;j++){
            if (getElemento(i,j) != 0)
                p=0;
        }
    }
    if(p==1)
        return true;
    else
        return false;
}

bool Matriz::matrizIdentidade()const{ //CERTO
    int p = 1;
    for(int i=0;i<getQuantidadeDeLinhas();i++){
            for(int j =0;j<getQuantidadeDeColunas();j++){
                if((i==j) && (getElemento(i,j) != 1))
                   p=0;
                else if((i != j) && (getElemento(i,j) != 0))
                   p=0;
            }
        }
    if(p==1)
        return true;
    else
        return false;
}

bool Matriz::matrizTriangInferior()const{ //CERTO
    int p=1;
    for (int i=0; i < getQuantidadeDeLinhas(); i++){
        for (int j=(i+1); j < getQuantidadeDeColunas();j++){
            if (getElemento(i,j) != 0)
                p=0;
        }
    }
    if(p==1)
        return true;
    else
        return false;
}

bool Matriz::matrizSimetrica()const{ //CERTO
    if((*this) == this->matrizTransp())
        return true;
    else
        return false;
}


Matriz* Matriz::multiplicarK(int n){ //CERTO
    try{
        Matriz *aux= new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
        for(int linha = 0; linha<quantidadeDeLinhas;linha++)
            for(int coluna = 0;coluna<quantidadeDeColunas;coluna++){
                int valor = getElemento(linha,coluna)*n;
                aux->setElemento(valor,linha,coluna);
            }
        return aux;

    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }catch(QString &erro){
        throw QString("Matriz auxiliar nao criada nao podemos adicionar as matrizes");
    }
}

Matriz* Matriz::potencia(int n)const{ //CERTO
    try{
        Matriz *aux = new Matriz(quantidadeDeLinhas, quantidadeDeColunas);
        if(n==0){
            for(int linha = 0; linha<quantidadeDeLinhas;linha++)
                for(int coluna = 0;coluna<quantidadeDeColunas;coluna++){
                    if(linha == coluna) aux->setElemento(1,linha,coluna);
                    if(linha != coluna) aux->setElemento(0,linha,coluna);
                }
            return aux;
        }
        for(int linha = 0; linha<quantidadeDeLinhas;linha++)
            for(int coluna = 0;coluna<quantidadeDeColunas;coluna++){
                aux->setElemento(this->getElemento(linha,coluna),linha,coluna);
            }
        while(n>1){
            aux = (*this) *(aux);
            n--;
        }
        return aux;
    }catch(std::bad_alloc&){
        throw QString("Vai comprar memoria");
    }
}

bool Matriz::ortogonal()const{ //CERTO
    Matriz *aux = new Matriz(quantidadeDeLinhas, quantidadeDeColunas);
    aux = (*this)*this->matrizTransp();
    if(aux->matrizIdentidade() == true){
        return true;
        delete aux;
    }
    else{
        return false;
        delete aux;
    }
}

bool Matriz::permutacao()const{ //CERTO
    int soma=0,p=1;

    for(int linha = 0; linha<quantidadeDeLinhas;linha++){
        for(int coluna = 0;coluna<quantidadeDeColunas;coluna++)
            soma = soma + getElemento(linha,coluna);
        if(soma != 1)
            p=0;
        soma=0;
    }

    soma=0;

    for(int linha = 0; linha<quantidadeDeLinhas;linha++){
        for(int coluna = 0;coluna<quantidadeDeColunas;coluna++){
            soma = soma +getElemento(linha,coluna);
            }
    if(soma != 1)
        p=0;
    soma=0;
    }

    if(p==1)
        return true;
    else
        return false;
}


}//fim
