#include <iostream>
#include <stdlib.h>
#include "Continue.h"
#include "CDado.h"
using namespace std;

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

  Continue con;

};

Players::Players(){
	iD = 1;
	casilla = 1;
}

Players::Players(int _iD){
  iD = _iD;
	casilla = 1;
}

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

int Players::throwDice(){
	CDado dado;
	int n_dado = dado.GetValorDado();
	casilla = casilla + n_dado;
	if (casilla > 30){
		casilla = 30;
	}
	return n_dado;
}