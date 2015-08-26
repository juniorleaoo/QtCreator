#include "ContatoPersistencia.h"
namespace agenda{//inicio
ContatoPersistencia::ContatoPersistencia(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{

}

void ContatoPersistencia::incluir(Contato &objeto) const{
    std::ofstream arquivoAgenda;
    arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str(),
                                   std::ios::out|std::ios::app);
    if(!arquivoAgenda.is_open()){
        throw QString("Arquivo de Agenda nao foi aberto - Metodo incluir");
    }
    arquivoAgenda<<objeto.desmontarObjeto().toStdString()+"\n";
    arquivoAgenda.close();
}

void ContatoPersistencia::excluir(QString nome) const{
    try{
        std::stack<Contato> pilhaTeste;
        std::fstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str(),std::ios::in);
        if(!arquivoAgenda.is_open())
            throw QString ("Arquivo nao criado");
        std::string linha;
        bool resultado = true;
        std::getline(arquivoAgenda, linha);
        Contato *aux;
        while(!arquivoAgenda.eof()){
            Contato *pt = new Contato;
            QString str = linha.c_str();
            pt->montarObjeto(str);
            std::getline(arquivoAgenda, linha);
            if(nome != pt->getNome())
                pilhaTeste.push(*pt);
            else{
                resultado = true;
                aux = pt;
            }
        }
        delete aux;
        arquivoAgenda.close();        
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str(), std::ios::out);
        if(!arquivoAgenda.is_open())
            throw QString ("Arquivo nao criado");
        while(!pilhaTeste.empty()){
            Contato objeto;
            objeto = pilhaTeste.top();
            arquivoAgenda<<objeto.desmontarObjeto().toStdString()+"\n";
            pilhaTeste.pop();
        }
        arquivoAgenda.close();
        if(!resultado) throw QString("Nome nao esta cadastrado(excluir)");
    }catch(std::bad_alloc&){
        throw QString("nao ha memoria suficiente.");

}
}

std::list<Contato>* ContatoPersistencia::listagem()const{
    try{
       std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open()) throw QString("Arquivo nao encontrado.");
        std::list<Contato>* listaTeste = new std::list<Contato>;
        std::string linha;
        getline(arquivoAgenda,linha);
        //Contato obj;
        while(!arquivoAgenda.eof()){
            Contato *pt = new Contato;
            QString str = QString::fromStdString(linha);
            pt->montarObjeto(str);
            //obj.montarObjeto(str);
            listaTeste->push_back(*pt);
            getline(arquivoAgenda,linha);            
        }
        //listaTeste->sort();
        arquivoAgenda.close();
        return listaTeste;
    }catch(std::bad_alloc&){
        throw QString("nao ha memoria suficiente.");
    }
}

void ContatoPersistencia::editar(Contato &objeto)const{
    //estou excluindo o contato para depois adicionar da maneira que o usuario deseja   
    excluir(objeto.getNome());
    incluir(objeto);
}

std::list<Contato>* ContatoPersistencia::buscar(QString nome) const{
    try{
        std::list<Contato> *lista = listagem();
        std::list<Contato> *lista2 = new std::list<Contato>;
        bool resultado = false;
        for (std::list<Contato>::iterator i = lista->begin(); i != lista->end(); i++) {
            Contato *aux = new Contato;
            *aux = *i;
            if(aux->getNome() == nome){
                lista2->push_back(*aux);
                resultado = true;
            }
            else delete aux;
        }
        if (!resultado) throw QString("Nome nao esta cadastrado(Busca)");
        return lista2;
    }catch(std::bad_alloc&){
        throw QString("nao ha memoria suficiente.");
    }
}
}//fim


