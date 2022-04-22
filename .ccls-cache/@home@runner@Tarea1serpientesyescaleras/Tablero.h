#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Casillas.h"
using namespace std;

class Tablero{
	private:
	string tab [30];
  int veces_N = 22;
  int veces_L = 3;
  int veces_S = 3;
	
	public:
	Tablero();
	Tablero(Casilla,Snake,Ladder);
	string getTablero(int);
};

Tablero::Tablero(){}

Tablero::Tablero(Casilla N,Snake S,Ladder L){
	tab[0] = N.getNombre();
  tab[29] = N.getNombre();
	for(int i = 1; i < 28; i++){
    int letra = rand() % 3 + 1;

    if(letra == 2 && veces_L != 0)
    {
      tab[i] = L.getNombre();
			veces_L = veces_L - 1;
    }
    else if(letra == 3 && veces_S != 0)
    {
      tab[i] = S.getNombre();
			veces_S = veces_S - 1;
    }
		else
    {
      tab[i] = N.getNombre();
			veces_N = veces_N - 1;
    }
	}
  //for(int i=0;i<30;i++){
    //tab[i]=N.getNombre();
    //}
  //tab[4]=L.getNombre();
  //tab[15]=L.getNombre();
  //tab[27]=L.getNombre();
  //tab[9]=S.getNombre();
  //tab[17]=S.getNombre();
  //tab[29]=S.getNombre();
}

string Tablero::getTablero(int _num){
	return tab[_num];
}