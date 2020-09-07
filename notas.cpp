#include<iostream>
#include "notas.h"

Notas::Notas(std::string texto){
  _texto = texto;
}


void Notas::set(std::string texto){
  _texto = texto;
}

void Notas::show(){
  std::cout << _texto;
}