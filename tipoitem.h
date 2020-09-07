#ifndef TIPOITEM
#define TIPOITEM

typedef int TipoChave; // TipoChave é um inteiro

class TipoItem{
    private:
        TipoChave chave;
        // outros membros
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();    
};

#endif