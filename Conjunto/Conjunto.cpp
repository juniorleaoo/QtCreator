#include "Conjunto.h"
namespace TP1{
Conjunto::Conjunto(int tamanho):
    tamanho(0),
    indiceDeUso(0),
    array(0)
{
    if(tamanho<0) throw QString("O tamanho nao pode ser <0");
    try{
    array = new int[tamanho];
    //new funciona para criar um espaço de memoria dinamicamente
    //sempre que tiver um new, tem que por um delete
    this->tamanho=tamanho;
    }catch(std::bad_alloc&){
        throw QString("Sua maquina esta desmoriada");
    }
}

void Conjunto::setElemento(int elemento){
    if(indiceDeUso==tamanho) throw QString("Conjunto cheio");
    if(buscar(elemento)) throw QString("O elemento ja existe");
    array[indiceDeUso]= elemento;
    indiceDeUso ++;
    //busca é procurar algo em algum lugar
}

bool Conjunto::buscar(int elemento)const{
    for(int pos=0;pos<indiceDeUso;pos++){
        if(elemento==array[pos]) return true;
    }
    return false;
}

QString Conjunto::getConjunto()const{
    QString saida="{";
    for(int pos=0; pos<indiceDeUso;pos++){
        saida += QString::number(array[pos]);
        if(pos<indiceDeUso-1) saida+=",";
    }
    saida += "}";
    return saida;
}

Conjunto * Conjunto::calcularUniao(Conjunto const * const objeto)const{
    try {
        int tamanho = this->indiceDeUso + objeto->getIndiceDeUso();
        Conjunto *conjuntoAux = new Conjunto(tamanho);
        for(int pos = 0; pos < this->indiceDeUso; pos++){
            conjuntoAux->array[pos] = this->array[pos];
            conjuntoAux->indiceDeUso++;
        }
        for(int pos = 0 ; pos < objeto->indiceDeUso ; pos++){
            try {
                conjuntoAux->setElemento(objeto->array[pos]);
            } catch (...) {
            }
        }
        return conjuntoAux;
    } catch(std::bad_alloc&){
        throw QString("Conjunto Uniao nao pode ser criado - Memoria");
    }
}

Conjunto * Conjunto::calcularIntersecao(Conjunto const * const objeto)const{
    try {
        int tamanho = 0;
        if(this->indiceDeUso < objeto->getIndiceDeUso()) tamanho = this->indiceDeUso;
            else tamanho = objeto->getIndiceDeUso();
        Conjunto *conjuntoAux = new Conjunto(tamanho);
        for(int pos = 0; pos < this->indiceDeUso; pos++){
            if(objeto->buscar(this->array[pos])){
                conjuntoAux->array[conjuntoAux->indiceDeUso] = this->array[pos];
                conjuntoAux->indiceDeUso++;
            }
        }
        return conjuntoAux;
    } catch(std::bad_alloc&){
        throw QString("Conjunto Intersecao nao pode ser criado - Memoria");
    }
}

Conjunto * Conjunto::calcularDiferenca(Conjunto const * const objeto)const{
    try {
        int tamanho = 0;
        if(this->indiceDeUso < objeto->getIndiceDeUso()) tamanho = this->indiceDeUso;
            else tamanho = objeto->getIndiceDeUso();
        Conjunto *conjuntoAux = new Conjunto(tamanho);
        for(int pos = 0; pos < this->indiceDeUso; pos++){
            if(!objeto->buscar(this->array[pos])){
                conjuntoAux->array[conjuntoAux->indiceDeUso] = this->array[pos];
                conjuntoAux->indiceDeUso++;
            }
        }
        return conjuntoAux;
    } catch(std::bad_alloc&){
        throw QString("Conjunto Uniao nao pode ser criado - Memoria");
    }
}

bool Conjunto::eSubConjunto(Conjunto const * const objeto)const{
        if (calcularDiferenca(objeto)->indiceDeUso==0)
            return true;
        else return false;
}

bool Conjunto::eIdentico(Conjunto const * const objeto)const{
    if (calcularDiferenca(objeto)->indiceDeUso==0 && objeto->calcularDiferenca(this))
        return true;
    else return false;
}

bool Conjunto::eDisjunto(Conjunto const * const objeto) const{
    if(calcularIntersecao(objeto)->indiceDeUso==0)
        return true;
    else return false;
}

int Conjunto::calculaAmplitude()const{
    int maior = array[0], menor = array[0];
    for(int i=1;i<indiceDeUso;i++){
        if (maior < array[i])
        maior = array[i];
        if (menor > array[i])
        menor = array[i];
}
    maior=maior-menor;
    return maior;
}

int Conjunto::calcularProdutoEscalar(Conjunto const * const objeto)const{
    int soma = 0;
    for(int i=0;i<indiceDeUso;i++){
        soma+=  this->array[i]*objeto->array[i];
    }
    return soma;
}

Conjunto *Conjunto::maiorSubCadeiaCrescente()const{
try{
int tamanho = this->indiceDeUso;
Conjunto *conjuntoAux = new Conjunto(tamanho);
    int pi=0, mpi=0, mpf=0;
    for(int i=0,pf=0;i<indiceDeUso-1;i++){
        if(array[i+1]<array[i]){
            pf=i;
            if(pf-pi>mpf-mpi){
                mpi=pi;
                mpf=pf;
            }
            pi=i+1;
        }
        else if(i==indiceDeUso-2){
            pf=i+1;
            if(pf-pi>mpf-mpi){
                mpi=pi;
                mpf=pf;
            }
        }
    }
for(int i=mpi,j=0;i<=mpf;i++){
     conjuntoAux->array[j]=this->array[i];
     conjuntoAux->indiceDeUso++;
     j++;
 }
return conjuntoAux;
} catch(std::bad_alloc&){
    throw QString("Conjunto Uniao nao pode ser criado - Memoria");
}
}

Conjunto *Conjunto::maiorSubCadeiaDecrescente()const{
    try{
    int tamanho = this->indiceDeUso;
    Conjunto *conjuntoAux = new Conjunto(tamanho);
        int pi=0, mpi=0, mpf=0;
        for(int i=0,pf=0;i<indiceDeUso-1;i++){
            if(array[i+1]>array[i]){
                pf=i;
                if(pf-pi>mpf-mpi){
                    mpi=pi;
                    mpf=pf;
                }
                pi=i+1;
            }
            else if(i==indiceDeUso-2){
                pf=i+1;
                if(pf-pi>mpf-mpi){
                    mpi=pi;
                    mpf=pf;
                }
            }
        }
    for(int i=mpi,j=0;i<=mpf;i++){
         conjuntoAux->array[j]=this->array[i];
         conjuntoAux->indiceDeUso++;
         j++;
     }

    return conjuntoAux;

    } catch(std::bad_alloc&){
        throw QString("Conjunto Uniao nao pode ser criado - Memoria");
    }
}

Conjunto *Conjunto::ordenar(Conjunto const * const objeto)const{
        int aux;
        Conjunto *conjuntoAux=this->calcularUniao(objeto);

        for(int i=0;i<=conjuntoAux->indiceDeUso-1;i++){
            for(int j=0;j<=conjuntoAux->indiceDeUso-1;j++){
                if(conjuntoAux->array[i] < conjuntoAux->array[j]){
                    aux=conjuntoAux->array[j];
                    conjuntoAux->array[j]=conjuntoAux->array[i];
                    conjuntoAux->array[i]=aux;
                }
            }
        }
return conjuntoAux;
}

float Conjunto::calcularMedia()const{
    float soma = 0;
    for(int i=0;i<indiceDeUso;i++){
        soma=soma+array[i];
    }
    soma=soma/indiceDeUso;
    return soma;
}
}

