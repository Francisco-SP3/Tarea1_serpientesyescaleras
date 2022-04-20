//Francisco Salas Porras A01177893
//Iván López A01284875
//Gabriel Ruiz Miller A00835179

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Continue.h"
using namespace std;

//class MyGame{
//	private:
//	
//	public:
//};

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

//class Tile{
//	private:
//	string tablero;
//	public:
//	Tile();
//	Tile(string);
//	~Tile();
//};
//
//Tile::Tile(){
//	
//}
//
//Tile::Tile(string _s){
//	
//};

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
	Continue continuar;
	continuar.setcon();
	chrono::seconds dura(2);
	this_thread::sleep_for(dura);
	cout << continuar.getcon() << endl;
}