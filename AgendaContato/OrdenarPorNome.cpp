#include "OrdenarPorNome.h"

namespace agenda{//inicio

bool OrdenarPorNome::ePrimeiro(Contato &c1, Contato &c2){
    if(c1.getNome() <= c2.getNome()) return true;
    else return false;
}
/*
void OrdenarPorNome::ordenar(std::list<Contato> *lista){
    lista->sort();
}

bool operator <(Contato &c1, Contato &c2){
    return c1.getNome()<c2.getNome();
}
*/
}//fim

