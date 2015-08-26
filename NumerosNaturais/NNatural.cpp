#include "NNatural.h"
namespace TP1{

void NNatural::set(long numero){
    if(numero<0) throw QString ("O valor do numero não pode ser < 0");
    this->numero=numero;
    //o atributo sempre troca de cor
    //sempre que eu usar this eu vou ir para o escopo da classe
}

NNatural NNatural::calcularFatoria()const{
    long aux = this->numero;
    long fat = 1;
    for(;aux>0;aux--) fat*=aux; //fatorial
    NNatural  x;
    x.set(fat);
    return x;
}

bool NNatural::eQuadradoPerfeito()const{
    int valor = sqrt(numero);
    if((valor*valor)==numero) return true;
    else return false;
}

bool NNatural::eCapicua()const{
    int aux = numero;
    int soma = 0;
    while(aux!=0){
        soma=soma*10+(aux%10);
        aux=aux/10;
    }
    if(soma==numero) return true;
    else return false;
}

bool NNatural::eNumeroPerfeito()const{
    int aux=this->numero;
    int soma = 0;
    for(int cont=1;cont<aux;cont++){
        if(aux%cont==0) soma=soma+cont;
    }
    if(soma==aux) return true;
    else return false;
}

bool NNatural::eNumeroPrimo()const{
    int aux = numero;
    int quant = 0;
    for(int cont=1;cont<aux;cont++){
        if(aux%cont==0) quant++;
    }
    if (quant == 1) return true;
    else return false;
}
NNatural NNatural::MMC(NNatural &numero)const{
    int n1= this->numero;
    int n2= numero.numero;
    int MMC = 1, i;
    for (i=2;;i++){
        while (n1%i==0 || n2%i==0){
            MMC *= i;
            if (n1%i==0)
                n1 /= i;
            if (n2%i==0)
                n2 /=i;
        }
        if (n1==1 && n2 ==1) break;
    }
    NNatural aux(MMC);
    return  aux;
}

NNatural NNatural::MDC(NNatural &numero) const{
    int x = this->numero;
    int y = numero.numero;
    int resto;
    while (y!=0){
        resto=x%y;
        x=y;
        y=resto;
    }
    NNatural aux2(x);
    return aux2;
}
bool NNatural::ePrimoSi(NNatural &numero)const{
    bool y;
    int x = this->MDC(numero).get();
    if(x==1) y= true;
    else y=false;
    return y;
}

NNatural NNatural::Base2()const{
    long aux=this->numero;
    int exp=0;
    long valor = 0;
    while(aux>0){
        valor = valor+(aux%2)*pow(10,exp);
        exp ++;
        aux = aux/2;
    }
    NNatural  x;
    x.set(valor);
    return x;
}
NNatural NNatural::Base8()const{
    long aux=this->numero;
    int exp=0;
    long valor = 0;
    while(aux>0){
        valor = valor+(aux%8)*pow(10,exp);
        exp ++;
        aux = aux/8;
    }
    NNatural  x;
    x.set(valor);
    return x;
}
QString NNatural::base16()const{
    QString vet= "0123456789ABCDEF";
    int aux = numero;
    QString saida="";
    while (aux>0){
    saida=vet[aux%16]+saida;
    aux=aux/16;
    }
    return saida;
}

}


