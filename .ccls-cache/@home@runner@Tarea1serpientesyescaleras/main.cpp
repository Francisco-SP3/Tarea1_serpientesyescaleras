//Francisco Salas Porras A01177893
//Iván López A01284875
//Gabriel Ruiz Miller A00835179

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Continue.h"
#include "CDado.h"
#include "MyGame.h"
using namespace std;

//class Player{
//	private:
//	int num;
//	int pos;
//
//	public:
//	Player();
//	Player(int);
//	~Player();
//	string numplayer();
//	int throwdice();
//	
//};



// class Dice{
//
//};

class Tile{

	private:
	string casilla;
	//Players p1;
	//Players p2;

	public:
	Tile();
	Tile(string);
	~Tile();
};

Tile::Tile(){
	casilla = "N";
}

Tile::Tile(string _casilla){
	casilla = _casilla;
};



//class Serpiente : public Tile{
//	private:
//	int punish;
//	public:
//	Serpiente();
//	~Serpiente();
//	int setpunish();
//	int getpunish();
//
//};

//class Ladder : public Tile{
//	private:
//	int reward;
//	public:
//	Escalera();
//	~Escalera();
//	int setreward();
//	int getreward();
//};

//class Tablero{
//	private:
//	string tablero;
//
//	public:
//	Tablero();
//	~Tablero();
//	
//};
			// for i 2:29

int main() {
	MyGame juego;
	juego.startGame();
	
	Continue continuar;
	CDado tiraDado;
	continuar.setcon();
	cout << tiraDado.GetValorDado() << endl;
}