#include "Contato.h"
namespace agenda{//inicio
Contato::Contato():
    nome(""),
    enderecoResidencial("", "", ""),
    enderecoTrabalho(0),
    email("")
{
    for(int pos=0; pos<3; pos++)
        telefoneDeContatos[pos]=0;
}

Contato::Contato(QString nomeP, Telefone *telefonesDeContatosP[3], Endereco enderecoResidencialP, Endereco *enderecoTrabalhoP, QString emailP):
   nome(nomeP),
   enderecoResidencial(enderecoResidencialP),
   enderecoTrabalho(enderecoTrabalhoP),
   email(emailP)

{
    for(int pos=0; pos<3; pos++)
        telefoneDeContatos[pos]=telefonesDeContatosP[pos];
}

void Contato::setEnderecoTrabalho(Endereco *objeto){
    if(this->enderecoTrabalho) delete this->enderecoTrabalho;
    enderecoTrabalho = objeto;
}

void Contato::setTelefoneTrabalho(Telefone *telefoneTrabalho){
    if(this->telefoneDeContatos[0]) delete this->telefoneDeContatos[0];
    telefoneDeContatos[0]=telefoneTrabalho;
}

void Contato::setTelefoneResidencial(Telefone *telefoneResidencial){
    if(this->telefoneDeContatos[1]) delete this->telefoneDeContatos[1];
    telefoneDeContatos[1]=telefoneResidencial;
}

void Contato::setTelefoneCelular(Telefone *telefoneCelular){
    if(this->telefoneDeContatos[2]) delete this->telefoneDeContatos[2];
    telefoneDeContatos[2]=telefoneCelular;
}


Contato::~Contato()
{
    for(int pos=0; pos<3; pos++)
        if(telefoneDeContatos[pos]!=0)
            delete telefoneDeContatos[pos];

    if(enderecoTrabalho!=0)
      delete enderecoTrabalho;//Dúvida
}

void Contato::montarObjeto(QString &str){
    try{
        QStringList strList = str.split(';');
        if(strList.length() != 17) throw QString ("Erro ao montar o objeto");
        nome = strList[0];
        Telefone *trabalho = new Telefone(strList[1].toInt(), strList[2].toInt(), strList[3].toLong());
        Telefone *residencial = new Telefone(strList[4].toInt(), strList[5].toInt(), strList[6].toLong());
        Telefone *celular= new Telefone(strList[7].toInt(), strList[8].toInt(), strList[9].toLong());
        telefoneDeContatos[0] = trabalho;
        telefoneDeContatos[1] = residencial;
        telefoneDeContatos[2] = celular;
        enderecoResidencial.setLogradouro(strList[10]);
        enderecoResidencial.setCEP(strList[11]);
        enderecoResidencial.setNumero(strList[12]);
        Endereco *endereco = new Endereco(strList[13],strList[14],strList[15]);
        enderecoTrabalho = endereco;
        email = strList[16];
    }catch(...){
        throw QString ("Erro no metodo materializar classe contato");
    }
}

QString Contato::desmontarObjeto()const{
    QString saida;
    saida = nome + ";";
    for(int cont = 0; cont < 3; ++cont){
        saida += QString::number(telefoneDeContatos[cont]->getDDI()) + ";";
        saida += QString::number(telefoneDeContatos[cont]->getDDD()) + ";";
        saida += QString::number(telefoneDeContatos[cont]->getNumero()) + ";";
    }
    saida += enderecoResidencial.getLogradouro() + ";";
    saida += enderecoResidencial.getCEP() + ";";
    saida += enderecoResidencial.getNumero() + ";";
    saida += enderecoTrabalho->getLogradouro() + ";";
    saida += enderecoTrabalho->getCEP() + ";";
    saida += enderecoTrabalho->getNumero() + ";";
    saida += email;
    return saida;
}
}//fim
