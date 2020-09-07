#ifndef NOTAS
#define NOTAS

#include <vector>

class Notas{
  private:
  std::string _texto;

  public:
  Notas(std::string texto);
  void set(std::string);
  void show();

};


#endif