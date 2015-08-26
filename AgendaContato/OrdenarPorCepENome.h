#ifndef ORDENARPORCEPENOME_H
#define ORDENARPORCEPENOME_H
#include<OrdenadorTemplateMethod.h>

namespace agenda{//inicio
class OrdenarPorCepENome:public OrdenadorTemplateMethod
{
public:
    bool ePrimeiro(Contato &c1, Contato &c2);
};



}//fim
#endif // ORDENARPORCEPENOME_H
