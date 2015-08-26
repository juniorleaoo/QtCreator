#include "OrdenarPorCepENome.h"

namespace agenda {//inicio

bool OrdenarPorCepENome::ePrimeiro(Contato &c1, Contato &c2){
    if(c1.getEnderecoResidencial().getCEP() < c2.getEnderecoResidencial().getCEP()) return true;
    else
        if(c1.getEnderecoResidencial().getCEP()==c2.getEnderecoResidencial().getCEP())
            if(c1.getNome() <= c2.getNome()) return true;
            else return false;
        else return false;
}

}//fim
