// Francisco Salas Porras A01177893

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;

class MyGame{
	private:
	//Players p1;
	//Players p2;
	//Tablero tab;
	
	public:
	MyGame();
	~MyGame();
	void startGame();
	void gameRules();
	void playGame();
};

MyGame::MyGame(){
	
}

MyGame::~MyGame(){}

void MyGame::startGame(){
	chrono::seconds dura(2);
	string inicio;
	
	cout << "Start game? \nYes (Y) | No (Any other key)" << endl;
	cin >> inicio;
	
	if (inicio == "Y" || inicio == "y"){
		cout << "\nStarting..." << endl;
		this_thread::sleep_for(dura);
		cout << "\nWelcome to Snakes & Ladders!" << endl;
		MyGame juego;
		juego.gameRules();
	}
	else{
		cout << "\nOkay, bye" << endl;
	}
}

void MyGame::gameRules(){
	chrono::seconds dura(2);
	chrono::seconds dura5(5);
	chrono::seconds dura1(1);
	string reglas;

	cout << "\nWould you like to know the rules? \nYes (Y) | No (Any other key)" << endl;
	cin >> reglas;
	
	if (reglas == "Y" || reglas == "y"){
		while (true){
			cout << "\nHere are the rules..." << endl;
			this_thread::sleep_for(dura1);
			cout << "\nReglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas Reglas" << endl;
			this_thread::sleep_for(dura5);
			cout << "\nWould you like to hear them again? \nYes (Y) | No (Any other key)" << endl;
			cin >> reglas;
			if (reglas == "Y" || reglas == "y"){
				continue;
			}
			else{
				break;
			}
		}
	}
	else{}
	
	cout << "\nAlright then, let's begin!" << endl;
	this_thread::sleep_for(dura);
	MyGame juego;
	juego.playGame();
}

void MyGame::playGame(){
	cout << "\nJugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando Jugando" << endl;
}