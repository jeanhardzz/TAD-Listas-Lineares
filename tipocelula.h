#include "tipoitem.h"
class TipoCelula{
    public:
        TipoCelula();
    private:
        TipoItem item;
        TipoCelula *prox;
        friend class ListaEncadeada;
};