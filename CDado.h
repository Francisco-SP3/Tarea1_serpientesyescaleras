#include <ctime>
#include <cstdlib>

class CDado{
  public:
    CDado();
    int GetValorDado();
};

CDado::CDado(){
  srand(time(0));
}
// Generador del valor del dado para cada turno
int CDado::GetValorDado(){
  return  (rand() % 6) + 1;
}