#ifndef LISTA_ARRANJO
#define LISTA_ARRANJO

#include "lista.h"

class ListaArranjo : public Lista{
    private:
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];
    public:
        ListaArranjo() : Lista() {};
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
    
};

#endif