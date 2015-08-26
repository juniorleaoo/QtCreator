#ifndef TELEFONE_H
#define TELEFONE_H
namespace agenda//Inicio
{
class Telefone
{
private:
    int DDI;
    int DDD;
    long numero;
public:
    Telefone(int DDI, int DDD, long numero);
    void setDDI(int DDI){this->DDI=DDI;}
    void setDDD(int DDD){this->DDD=DDD;}
    void setNumero(int numero){this->numero=numero;}
    int getDDI()const{return DDI;}
    int getDDD()const{return DDD;}
    int getNumero()const{return numero;}

};

}//Fim
#endif // TELEFONE_H
