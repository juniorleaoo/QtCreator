#ifndef CONTATOPERSISTENCIA_H
#define CONTATOPERSISTENCIA_H
#include<CRUD.h>
#include<fstream>
#include<stack>
#include<QString>

//#include<iostream>
//#include<cctype>

//********HERANÇA, CLASSE CONTATOPERSISTENCIA HERDANDO DA CLASSE CRUD DE MODO PUBLICO
namespace agenda{//inicio
class ContatoPersistencia:public CRUD
{
private:
    QString nomeDoArquivoNoDisco;
public:
    ContatoPersistencia(QString nomeDoArquivoNoDisco);
    void incluir(Contato &objeto) const;
    void excluir(QString nome)const;
    std::list<Contato>* listagem()const;
    void editar(Contato &objeto)const;
    std::list<Contato>* buscar(QString nome)const;
};
}//fim
#endif // CONTATOPERSISTENCIA_H
