#ifndef MATRIZ_H
#define MATRIZ_H
#include <QString>

namespace TP2{//inicio
class Matriz
{
private:
    int quantidadeDeColunas;
    int quantidadeDeLinhas;
    int *ptMatriz;
public:
    Matriz(int qLinhas, int qColunas);
    ~Matriz(){if(ptMatriz) delete[] ptMatriz;}

    int getQuantidadeDeLinhas()const {return quantidadeDeLinhas;}
    int getQuantidadeDeColunas()const{return quantidadeDeColunas;}

    void setElemento(int elemento, int linha, int coluna)const;
    int getElemento(int linha, int coluna)const;

    QString getMatriz()const;
    Matriz* matrizTransp()const;

    bool matrizTringSuperior()const;
    bool matrizIdentidade()const;
    bool matrizTriangInferior()const;
    bool matrizSimetrica()const;

    Matriz* operator +(Matriz const * const mat)const;/* o parametro está em ponteiro pois matA e matB é ponteiro, matC = matA+matB; matC=matA.adicionar(matB)
o parâmetro é um constante para uma constante, onde ele vai poder somente olhar o objeto*/


/*
* = pra onde aponta
& = ele pega o endereço da variavel


ponteiro para uma constante = ele aponta para várias mas não pode modificar para quem ele aponta
ponteiro constante = não esquecer de inicializar ele, ele só aponta para um lugar e não pode ser alterado para quem ele aponta, mas ele pode alterar o valor de quem ele aponta
ponteiro constante para uma constante = ele só pode ver o objeto, mas não pode deixar de apontar o objeto e nem alterar o valor do objeto que ele aponta
*/

    Matriz* operator *(Matriz const * const mat)const;
    Matriz* operator -(Matriz const * const mat)const;
    bool operator ==(Matriz const * const mat)const;
    bool operator !=(Matriz const * const mat)const;
    Matriz* multiplicarK(int n);
    Matriz* potencia(int n)const;

    bool ortogonal()const;
    bool permutacao()const;


};
} // fim
#endif // MATRIZ_H
