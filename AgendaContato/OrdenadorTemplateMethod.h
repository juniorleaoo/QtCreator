#ifndef ORDENADORTEMPLATEMETHOD_H
#define ORDENADORTEMPLATEMETHOD_H
#include<Contato.h>
#include<ContatoPersistencia.h>
#include<vector>
#include<algorithm>

namespace agenda{//inicio
class OrdenadorTemplateMethod
{
public:
    virtual bool ePrimeiro(Contato &c1, Contato &c2) = 0;
    //virtual void ordenar(std::list<Contato> *lista) = 0;
    void ordenar(std::list<Contato> &lista);
    //virtual bool compare(const Contato &c1,const Contato &c2)=0;
};



}//fim
#endif // ORDENADORTEMPLATEMETHOD_H
