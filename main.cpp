#include <iostream>

#include "lista.h"
#include "lista-arranjo.h"
#include "lista-encadeada.h"
#include "tipoitem.h"

main(){
    
    std::cout<<"num e q deu"<<std::endl;
    TipoItem x;
    ListaEncadeada l;
    x.SetChave(2);        
    l.InsereInicio(x); //2
    x.SetChave(5);
    l.InsereInicio(x); //52
    x.SetChave(9);
    l.SetItem(x,2); //59 
    l.Imprime();
}