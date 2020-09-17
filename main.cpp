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
    l.InsereInicio(x);
        
    x.SetChave(3);        
    l.InsereInicio(x);
    x.SetChave(4);
    x.SetChave(1);
    l.InsereInicio(x);
    l.InsereInicio(x);
    x.SetChave(6);
    l.InsereInicio(x);
    
    
    l.Imprime();
    l.MoveMenor();
    l.Imprime();
}