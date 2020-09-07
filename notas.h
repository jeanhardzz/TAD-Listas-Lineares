#ifndef NOTAS
#define NOTAS

#include <vector>
#include <string>

class Notas{
  private:
  std::string _texto;

  public:
  Notas(std::string texto);
  void set(std::string);
  void show();

};


#endif