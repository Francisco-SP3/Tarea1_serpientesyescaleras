#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Continue.h"
#include "Players.h"
#include "Tablero.h"
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
	
	cout << "\nStart game? \nYes (Y) | No (Any other key)" << endl;
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

// Temporizador
void MyGame::gameRules(){
	chrono::seconds dura(2);
	chrono::seconds dura5(5);
	chrono::seconds dura1(1);
	string reglas;

	cout << "\nWould you like to know the rules? \nYes (Y) | No (Any other key)" << endl;
	cin >> reglas;

  // Obtención de indicaciones de juego (Reglas)
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

  // Comienzo de juego, llamar a la función playGame
	cout << "\nAlright then, let's begin!" << endl;
	this_thread::sleep_for(dura);
	MyGame juego;
	juego.playGame();
}

void MyGame::playGame(){
	chrono::seconds dura(2);
	chrono::seconds dura4(4);
	chrono::seconds dura1(1);
	Continue con;
	Players p1(1);
	Players p2(2);
	Casilla cas;
	Snake snek;
	Ladder ladd;
	Tablero tab(cas,snek,ladd);
	int i = 1;
	
	while(true){
		cout << "\nTurn #" << i << endl;

		this_thread::sleep_for(dura);
		
		cout << "\nThis is your board:" << endl;

		this_thread::sleep_for(dura1);
		
		for(int i = 0;i<=29;i++){
			cout << tab.getTablero(i);
		}
		cout << "\n";
		
		this_thread::sleep_for(dura);
		
		cout << "\nIt's player " << p1.getID() << " 's turn!" << endl;

		this_thread::sleep_for(dura);

		cout << "\nThrowing dice..." << endl;

		this_thread::sleep_for(dura4);

		cout << "\nYou got a " << p1.throwDice() << "!" << endl;

		this_thread::sleep_for(dura1);
		
		cout << "\nYou are now at tile " << p1.getCasilla() << " which is an " << tab.getTablero(p1.getCasilla()-1) << endl;

		this_thread::sleep_for(dura4);
		
		con.setcon();
		
		if(con.getcon() == false){
			break;
		}
		
		cout << "\nIt's player " << p2.getID() << " 's turn!" << endl;

		this_thread::sleep_for(dura);

		cout << "\nThrowing dice..." << endl;

		this_thread::sleep_for(dura4);

		cout << "\nYou got a " << p2.throwDice() << "!" << endl;

		this_thread::sleep_for(dura1);
		
		cout << "\nYou are now at tile " << p2.getCasilla() << " which is an " << tab.getTablero(p2.getCasilla()-1) << endl;

		this_thread::sleep_for(dura4);
		
		con.setcon();
		
		if(con.getcon() == false){
			break;
		}

		i = i + 1;
	}
}