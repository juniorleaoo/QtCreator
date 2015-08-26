#ifndef TRANSFORMARDADOS_H
#define TRANSFORMARDADOS_H
#include<QString>
//********CLASSE INTERFACE
//********HERANÇA
namespace agenda{//inicio
class TransformarDados
{
public:
    virtual void montarObjeto(QString &str) = 0;
    virtual QString desmontarObjeto()const = 0;
};
}//fim
#endif // TRANSFORMARDADOS_H
