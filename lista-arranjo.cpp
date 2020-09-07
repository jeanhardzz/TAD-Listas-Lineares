#include "lista-arranjo.h"

TipoItem ListaArranjo::GetItem(int pos){
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
    return itens[pos-1];
}

void ListaArranjo::SetItem(TipoItem item, int pos){
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
    itens[pos-1] = item;
}