#ifndef CRUD_H
#define CRUD_H
#include<Contato.h>
#include <list>


//********CLASSE INTERFACE
//********CLASSE ABSTRATA (TEM MAIS DE UM METODO VIRTUAL PURO
//********METODOS VIRTUAIS PURO O MÉTODO NÃO É IMPLEMENTADO, MAS É OBRIGADO SER IMPLEMENTAR QUEM FOR HERDAR A CLASSE

namespace agenda{//inicio
class CRUD
{
public:
    virtual void incluir(Contato &objeto) const = 0;
    virtual void excluir(QString nome)const = 0;
    virtual std::list<Contato>* listagem()const = 0;
    virtual void editar(Contato &objeto)const =0;
    virtual std::list<Contato>* buscar(QString nome)const = 0;
};
}//fim
#endif // CRUD_H
