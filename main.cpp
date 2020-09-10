#include <iostream>

#include "lista.h"
#include "lista-arranjo.h"
#include "lista-encadeada.h"
#include "tipoitem.h"

main(){
    
    std::cout<<"num e q deu"<<std::endl;
    TipoItem x;
    ListaEncadeada l;
    x.SetChave(5);
    l.InsereOrdenado(x);
    x.SetChave(1);
    l.InsereOrdenado(x);
      
    x.SetChave(3);        
    l.InsereOrdenado(x);
    x.SetChave(4);
    l.InsereOrdenado(x);
    x.SetChave(1);
    l.InsereOrdenado(x);
    
    
    l.Imprime();
}