#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;

//
class Casilla{
	public:
	string nombre;
	int efecto;
	Casilla();
	Casilla(string,int);
	~Casilla();
	void setNombre(string);
	string getNombre();
	void setEfecto(int);
	int getEfecto();
  //int tablero[30];
};

Casilla::Casilla(){
	nombre = "N";
	efecto = 0;
}

Casilla::Casilla(string _nom, int _ef){
	nombre = _nom;
	efecto = _ef;
}

Casilla::~Casilla(){}

void Casilla::setNombre(string _nom){
	nombre = _nom;
}

string Casilla::getNombre(){
	return nombre;
}

void Casilla::setEfecto(int _ef){
	efecto = _ef;
}

int Casilla::getEfecto(){
	return efecto;
}

class Snake : public Casilla{
	public:
	Snake();
};

Snake::Snake(){
	nombre = "S";
	efecto = -3;
}

class Ladder : public Casilla{
  public:
	Ladder();
};

Ladder::Ladder(){
	nombre = "L";
	efecto = 3;
}