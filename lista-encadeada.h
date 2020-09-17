#include "lista.h"
#include "tipoitem.h"
#include "tipocelula.h"

class ListaEncadeada : public Lista {
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
        void Inverte();
        void InsereOrdenado(TipoItem item);
        void MoveMenor();
    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
};