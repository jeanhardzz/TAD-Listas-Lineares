#include <iostream>
#include "lista-encadeada.h"

ListaEncadeada::ListaEncadeada() : Lista() {
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada()
{
    Limpa();
    delete primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false){
    TipoCelula *p; int i;
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
    // Posiciona na célula anterior a desejada
    p = primeiro;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    // vai para a próxima
    // se antes for false
    if(!antes)
        p = p->prox;
    return p;
}

TipoItem ListaEncadeada::GetItem(int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    return p->item;
}
void ListaEncadeada::SetItem(TipoItem item, int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    p->item = item;
}

void ListaEncadeada::InsereInicio(TipoItem item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;
    if(nova->prox == 0)
        ultimo = nova;
};

void ListaEncadeada::InsereFinal(TipoItem item)
{
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};

void ListaEncadeada::InserePosicao(TipoItem item, int pos) {
    TipoCelula *p, *nova;
    p = Posiciona(pos,true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;
    if(nova->prox == 0)
        ultimo = nova;
};

TipoItem ListaEncadeada::RemoveInicio() {;
    TipoItem aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == 0)
        ultimo = primeiro;
    aux = p->item;
    delete p;
    return aux;
}

TipoItem ListaEncadeada::RemoveFinal() {
    TipoItem aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);
    p->prox = 0;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    return aux;
}

TipoItem ListaEncadeada::RemovePosicao(int pos) {;
    TipoItem aux;
    TipoCelula *p, *q;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == 0)
        ultimo = p;
    return aux;
}

TipoItem ListaEncadeada::Pesquisa(TipoChave c) {
    TipoItem aux;
    TipoCelula *p;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    p = primeiro->prox;
    aux.SetChave(-1);
    while (p!=0) {
        if (p->item.GetChave() == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
}

void ListaEncadeada::Imprime() {
    TipoCelula *p;
    p = primeiro->prox;
    while (p!=0) {
        p->item.Imprime();
        p = p->prox;
    }
    std::cout<<"\n";
}

void ListaEncadeada::Limpa() {
    TipoCelula *p;
    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

void ListaEncadeada::Inverte(){
    TipoCelula *p;
    TipoCelula *frente=NULL;
    TipoCelula *tras=NULL;
    TipoCelula *aux=NULL;

    p = primeiro->prox;
    frente= p->prox;
    
    while (frente!=NULL){ 
        aux=frente->prox;       
        frente->prox=p;
        p->prox=tras;
        primeiro->prox=frente;

        tras=p;
        p= frente;
        frente=aux;                
        
    }
    //Complexidade O(n)
    
}

void ListaEncadeada::InsereOrdenado(TipoItem item){
    TipoCelula *nova,*p,*aux;
    nova = new TipoCelula();
    nova->item = item;

    if (tamanho == 0){
        nova->prox = 0;
        primeiro->prox= nova;        
    }else{
        p = primeiro->prox;
        if(p->item.GetChave() > nova->item.GetChave()){
            primeiro->prox=nova;
            nova->prox=p;
        }else{
            while (p->prox!=0) {
                if (p->prox->item.GetChave() > nova->item.GetChave()) {
                    aux = p->prox;
                    p->prox = nova;
                    nova->prox = aux;
                    break;                
                }else if(p->prox->prox == 0){
                    p->prox->prox=nova;
                    nova->prox=0;
                    ultimo = nova;
                }
                p = p->prox;
            }
        }
        
    }
    tamanho++;        
}

void ListaEncadeada::MoveMenor(){    
    TipoCelula *menor,*p,*aux;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    menor=primeiro->prox;
    p=menor;
    
    while (p->prox!=0) {
            if (p->prox->item.GetChave() < menor->item.GetChave()) {                     
                menor=p->prox;
            }
            p = p->prox;
    }    
    p=primeiro->prox;
    if(p->item.GetChave()!=menor->item.GetChave()){
        while (p->prox!=0) {
            if (p->prox->item.GetChave() == menor->item.GetChave()) {                     
                if(p->prox->prox==0){                    
                    ultimo=p;
                    p->prox=0;
                    break;
                }else{
                    p->prox=p->prox->prox;
                }
                
                
            }            
            p = p->prox;
        }
        aux=primeiro->prox;
        primeiro->prox=menor;
        menor->prox=aux;
    }

}