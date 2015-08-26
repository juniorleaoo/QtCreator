#ifndef CONTATO_H
#define CONTATO_H
#include<QString>
#include<TransformarDados.h>
#include<QStringList>
#include <stack>
#include <Telefone.h>
#include <Endereco.h>

namespace agenda{//inicio
class Contato:public TransformarDados
{
private:
    QString nome;
    Telefone* telefoneDeContatos[3];
    Endereco enderecoResidencial;
    Endereco* enderecoTrabalho;
    QString email;
public:
    Contato();
    Contato(QString nomeP, Telefone *telefonesDeContatosP[3], Endereco enderecoResidencialP, Endereco *enderecoTrabalhoP, QString emailP);
    //get e set nome
    QString getNome()const{return nome;}
    void setNome(QString nome){this->nome=nome;}

    //get e set enderecoResidencial
    Endereco getEnderecoResidencial()const{return enderecoResidencial;}
    void setEnderecoResidencial(Endereco &objeto){enderecoResidencial = objeto;}

    //get e set enderecoTrabalho
    Endereco const* const getEnderecoTrabalho()const{return enderecoTrabalho;}
    void setEnderecoTrabalho(Endereco *objeto);

    //get e set Email
    QString getEmail()const{return email;}
    void setEmail(QString email){this->email=email;}

    //get e set Telefone Trabalho
    void setTelefoneTrabalho(Telefone *telefoneTrabalho);
    Telefone const * const getTelefoneTrabalho()const{return telefoneDeContatos[0];}

    //get e set Telefone residencial
    void setTelefoneResidencial(Telefone *telefoneResidencial);
    Telefone const * const getTelefoneResidencial()const{return telefoneDeContatos[1];}

    //get e set Telefone Celular
    void setTelefoneCelular(Telefone *telefoneCelular);
    Telefone const * const getTelefoneCelular()const{return telefoneDeContatos[2];}

    void montarObjeto(QString &str);
    QString desmontarObjeto()const;
    ~Contato();
};

}//fim
#endif // CONTATO_H
