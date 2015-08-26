#ifndef ENDERECO_H
#define ENDERECO_H
#include<QString>
namespace agenda//Inicio
{
class Endereco
{
private:
    QString logradouro;
    QString CEP;
    QString numero;
public:
    Endereco(QString logradouro, QString CEP, QString numero);
    void setLogradouro(QString logradouro){this->logradouro=logradouro;}
    void setCEP(QString CEP){this->CEP=CEP;}
    void setNumero(QString numero){this->numero=numero;}
    QString getLogradouro()const{return logradouro;}
    QString getCEP()const{return CEP;}
    QString getNumero()const{return numero;}
};

}//Fim
#endif // ENDERECO_H
