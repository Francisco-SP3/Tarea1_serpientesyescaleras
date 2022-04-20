#include <iostream>
#include <stdlib.h>
#include "CDado.h"
using namespace std;

//se define la clase Players con las características con las que cuentan los jugadores al iniciar el juego, como numero de identificacion y casilla en la que se encuentra 
class Players{
  private:
	int iD;
	int casilla;

	public:
	Players();
	Players(int);
	~Players();
  void CheckID();
  void setID(int);
	int getID();
	void setCasilla(int);
	int getCasilla();
	int throwDice();
};

Players::Players(){
	iD = 1;
	casilla = 1;
}

Players::Players(int _iD){
  iD = _iD;
	casilla = 1;
}

// setters y getters de la clase Players para identificar a cada uno de los jugadores con un numero que indica su orden de turno, así como la asignación de la casilla inicial para cada uno
Players::~Players(){}

void Players::setID(int _iD){
	iD = _iD;
}

int Players::getID(){
	return iD;
}

void Players::setCasilla(int _cas){
	casilla = _cas;
}

int Players::getCasilla(){
	return casilla;
}

// throwDice es una función que se encarga de obtener el valor del dado al haber sido lanzado dentro de "CDado.h", para posteriormente sumarselo a la posición de casilla en donde se encuentre el jugador.
int Players::throwDice(){
	CDado dado;
	int n_dado = dado.GetValorDado();
	casilla = casilla + n_dado;
	if (casilla > 30){
		casilla = 30; //no se sobrepasa la casilla 30 
	}
	return n_dado;
}