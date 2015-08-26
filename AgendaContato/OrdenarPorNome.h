#ifndef ORDENARPORNOME_H
#define ORDENARPORNOME_H
#include<OrdenadorTemplateMethod.h>

namespace agenda{//inicio
class OrdenarPorNome:public OrdenadorTemplateMethod
{
public:
    bool ePrimeiro(Contato &c1, Contato &c2);
    //void ordenar(std::list<Contato> *lista);
    //bool compare(const Contato &c1,const Contato &c2);
};

//bool operator <(Contato &c1, Contato &c2);

}//fim
#endif // ORDENARPORNOME_H
