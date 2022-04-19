#include <iostream>
#include <stdlib.h>
using namespace std;

class Players
{
  public:
  void SetID();
  int playerID = 2;
  bool lockID;
  int playerCasilla;

};

void Players::SetID()
{
  cout << "Prueba" << endl;
  lockID = false;
  if(playerID == 2)
  {
    playerID = 1;
    lockID = true;
  }
  else if(playerID == 1 && lockID == false)
  {
    playerID = 2;
  }
  cout << "Next turn to player:" << endl;
  cout << playerID << endl;
}