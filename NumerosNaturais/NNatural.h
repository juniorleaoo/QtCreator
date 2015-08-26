#ifndef NNATURAL_H
#define NNATURAL_H
#include <QString>
#include <math.h>

namespace TP1{//inicio
class NNatural
{
private:
    long numero;
public:
    NNatural():numero(0){}
    NNatural(long numero):numero(numero){}
    NNatural(NNatural &numero):numero(numero.numero){}
    long get()const{return numero;}
    void set(long numero);
    NNatural calcularFatoria()const;
    bool eQuadradoPerfeito()const;
    bool eCapicua()const;
    bool eNumeroPerfeito()const;
    bool eNumeroPrimo()const;
    NNatural MMC(NNatural &numero)const;
    NNatural MDC(NNatural &numero)const;
    bool ePrimoSi(NNatural &numero)const;
    NNatural Base2()const;
    NNatural Base8()const;
    QString base16()const;
};
}//fim
#endif // NNATURAL_H
