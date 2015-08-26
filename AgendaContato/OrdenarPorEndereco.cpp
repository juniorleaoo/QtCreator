#include "OrdenarPorEndereco.h"
namespace agenda{//inicio

bool OrdenarPorEndereco::ePrimeiro(Contato &c1, Contato &c2){
    if(c1.getEnderecoResidencial().getLogradouro() <= c2.getEnderecoResidencial().getLogradouro()) return true;
    else return false;
}



}//fim


