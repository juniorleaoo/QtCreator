#ifndef ORDENARPORENDERECO_H
#define ORDENARPORENDERECO_H
#include<OrdenadorTemplateMethod.h>

namespace agenda{//inicio
class OrdenarPorEndereco:public OrdenadorTemplateMethod
{
public:
    bool ePrimeiro(Contato &c1, Contato &c2);
};
}//fim

#endif // ORDENARPORENDERECO_H
