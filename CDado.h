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

int CDado::GetValorDado(){
  return  (rand() % 6) + 1;
}