#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "QString"
namespace TP1{
class Conjunto
{
private:
    int tamanho;
    int indiceDeUso;
    int *array;
    //ponteiro é uma variavel que armazena um endereço de memória,
    //o array é um ponteiro pois a criacao é dinamica, e para criar uma váriavel dinamica eu tenho que usar new
    //o new me retorna um endereço e por isso eu uso o array como ponteiro
    //o new solicita ao SO uma criação do espaço de memoria e me devolve o endereço desse espaço de memoria (especificamente um vetor)
    //o new lança uma execão de badalloc
    //o new só sai da memoria com o delete
    //o new tem que ter obrigatoriamente um delete para a váriavel não ficar na memoria
    //o destrutor ele tem o mesmo nome da classe mas com um til (~) na frente
public:
    Conjunto(int tamanho);
    ~Conjunto(){delete [] array;} //se o array existir ele apaga
    int getTamanho()const {return tamanho;} //const porque não altera os atributos
    int getIndiceDeUso()const{return indiceDeUso;}
    void setElemento(int elemento);
    bool buscar(int elemento)const;
    QString getConjunto()const; //a função dele é me devolver todo o conjunto, o formato do conjunto
    bool eConjuntoVazio()const {if(indiceDeUso==0) return true; else return false;}
    // estruturas complexas deve se usar passagem de valor por elemente (ponteiro ou referencia)
    Conjunto *calcularUniao(Conjunto const * const objeto) const;
    Conjunto *calcularIntersecao(Conjunto const * const objeto)const;
    Conjunto *calcularDiferenca(Conjunto const * const objeto)const;
    bool eSubConjunto(Conjunto const * const objeto)const;
    bool eIdentico(Conjunto const * const objeto)const;
    bool eDisjunto(Conjunto const * const objeto) const;
    int calculaAmplitude()const;
    int calcularProdutoEscalar(Conjunto const * const objeto)const;
    Conjunto *ordenar(Conjunto const * const objeto)const;
    Conjunto *maiorSubCadeiaCrescente()const;
    Conjunto *maiorSubCadeiaDecrescente()const;
    float calcularMedia()const;

};
}
#endif // CONJUNTO_H
