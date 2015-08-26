#include "OrdenadorTemplateMethod.h"
namespace agenda{

void OrdenadorTemplateMethod::ordenar(std::list<Contato> &lista){
    /*
    std::list<Contato> *lista2 = new std::list<Contato>;
    std::vector<Contato> vetor(lista.begin(),lista.end());
    int n = vetor.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(!ePrimeiro(vetor[i],vetor[j]) ){
                Contato *aux = new Contato();
                *aux = vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=*aux;
                //std::swap(vetor[i],vetor[j]);
            }
        }
    }

    //lista.clear();
    for(int i = 0; i < vetor.size(); i++){
        lista2->push_back(vetor[i]);
    }
    lista = *lista2;
    delete lista2;*/

    for (std::list<Contato>::iterator i = lista.begin(); i != lista.end(); i++) {
        for(std::list<Contato>::iterator j = i;j != lista.end(); j++){
            if(!ePrimeiro(*i,*j)){
                Contato *aux = new Contato;
                *aux = *i;
                *i = *j;
                *j = *aux;
            }
        }
    }
}


}







