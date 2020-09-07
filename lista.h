#ifndef LISTA
#define LISTA

#include "tipoitem.h"

class Lista{
    protected:
    int tamanho;

    public:
    //declarando algumas importantes direto aqui
    Lista() {tamanho =0;}
    int GetTamanho(){return tamanho;};
    bool Vazia(){return tamanho == 0;};

    //contrato com as filhas
    virtual TipoItem GetItem(int pos) = 0;
    virtual void SetItem(TipoItem item, int pos) = 0;
    virtual void InsereInicio(TipoItem item) = 0;
    virtual void InsereFinal(TipoItem item) = 0;
    virtual void InserePosicao(TipoItem item, int pos) = 0;
    virtual TipoItem RemoveInicio() = 0;
    virtual TipoItem RemoveFinal() = 0;
    virtual TipoItem RemovePosicao(int pos) = 0;
    virtual TipoItem Pesquisa(TipoChave c)= 0;
    virtual void Imprime() = 0;
    virtual void Limpa() = 0;

};

#endif