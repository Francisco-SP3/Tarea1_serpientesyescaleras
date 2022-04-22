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
			cout << "\nThere are 2 players. The first one to reach tile number 30 wins. If you land on an 'N' tile, nothing happens. If you land on an 'S' tile, you go back 3 tiles. If you land on an 'L' tile, you go forward 3 tiles. Player 1 is represented by the color red while player 2 by blue in the board. If both Players are in the same tile, they'll appear purple. You have only 10 tries." << endl;
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
	int casO;
	int efecto;
	string tileO;
	
	while(i <= 10){
		p1.setEfectoR(false);
		p2.setEfectoR(false);
		
		cout << "\nTurn #" << i << endl;

		this_thread::sleep_for(dura);
		
		cout << "\nThis is your board:" << endl;

		this_thread::sleep_for(dura1);
		
		for(int i = 0;i<=29;i++){
			if(p1.getCasilla()-1 == i && p2.getCasilla()-1 != i){
				cout << "\033[0;31m" << tab.getTablero(i) << "\033[0m";
			}
			else if(p2.getCasilla()-1 == i && p1.getCasilla()-1 != i){
				cout <<"\033[0;34m" << tab.getTablero(i) << "\033[0m";
			}
			else if(p1.getCasilla()-1 == i && p2.getCasilla()-1 == i){
				cout <<"\033[0;35m" << tab.getTablero(i) << "\033[0m";
			}
			else{
				cout << tab.getTablero(i);
			}
		}
		cout << "\n";
		
		this_thread::sleep_for(dura);
		
		cout << "\nIt's player " << p1.getID() << " 's turn!" << endl;
		this_thread::sleep_for(dura1);

		cout << "\nThrowing dice..." << endl;
		this_thread::sleep_for(dura4);
		cout << "You got a " << p1.throwDice() << "!" << endl;
		casO = p1.getCasillaO();
		this_thread::sleep_for(dura);
		
		cout << "\nYou are now at tile " << p1.getCasilla() << " which is an " << tab.getTablero(p1.getCasilla()-1) << endl;
		this_thread::sleep_for(dura);

		if(tab.getTablero(p1.getCasilla()-1) == "N"){
			cout << "Nothing happens... you stay put" << endl;
			efecto = 0;
			tileO = "N";
		}
		else if(tab.getTablero(p1.getCasilla()-1) == "S" && p1.getEfectoR() == false){
			cout << "Oh no! You slid three spaces!" << endl;
			tileO = "S";
			efecto = snek.getEfecto();
			p1.setCasilla(p1.getCasilla() + snek.getEfecto());
			if (p1.getCasilla() < 1){
				p1.setCasilla(1);
			}
			p1.setEfectoR(true);
			this_thread::sleep_for(dura);
			cout << "\nWhich gets you in tile " << p1.getCasilla() << endl;
		}
		else if(tab.getTablero(p1.getCasilla()-1) == "L"&& p1.getEfectoR() == false){
			cout << "Woohoo! You climbed three spaces!" << endl;
			tileO = "L";
			efecto = ladd.getEfecto();
			p1.setCasilla(p1.getCasilla() + ladd.getEfecto());
			if (p1.getCasilla() > 30){
				p1.setCasilla(30);
			}
			p1.setEfectoR(true);
			this_thread::sleep_for(dura);
			cout << "\nWhich gets you in tile " << p1.getCasilla() << endl;
		}
		this_thread::sleep_for(dura);

		if(p1.getCasilla() == 30){
			cout << "\nPlayer #1 is the winner" << endl;
			cout << "\n--GAME OVER--" << endl;
			break;
		}

		cout << "\nCurrent player information: " << i << p1.getID() << casO << p1.getNumDado() << tileO << efecto << endl;
		this_thread::sleep_for(dura4);
		
		con.setcon();
		
		if(con.getcon() == false){
			break;
		}

		cout << "\nThis is your board:" << endl;

		this_thread::sleep_for(dura1);
		
		for(int i = 0;i<=29;i++){
			if(p1.getCasilla()-1 == i && p2.getCasilla()-1 != i){
				cout << "\033[0;31m" << tab.getTablero(i) << "\033[0m";
			}
			else if(p2.getCasilla()-1 == i && p1.getCasilla()-1 != i){
				cout <<"\033[0;34m" << tab.getTablero(i) << "\033[0m";
			}
			else if(p1.getCasilla()-1 == i && p2.getCasilla()-1 == i){
				cout <<"\033[0;35m" << tab.getTablero(i) << "\033[0m";
			}
			else{
				cout << tab.getTablero(i);
			}
		}
		cout << "\n";
		
		this_thread::sleep_for(dura);
		
		cout << "\nIt's player " << p2.getID() << " 's turn!" << endl;
		this_thread::sleep_for(dura1);

		cout << "\nThrowing dice..." << endl;
		this_thread::sleep_for(dura4);
		cout << "\nYou got a " << p2.throwDice() << "!" << endl;
		casO = p2.getCasillaO();
		this_thread::sleep_for(dura);
		
		cout << "\nYou are now at tile " << p2.getCasilla() << " which is an " << tab.getTablero(p2.getCasilla()-1) << endl;
		this_thread::sleep_for(dura);
		
		if(tab.getTablero(p2.getCasilla()-1) == "N"){
			cout << "Nothing happens... you stay put" << endl;
			efecto = 0;
			tileO = "N";
		}

		else if(tab.getTablero(p2.getCasilla()-1) == "S" && p2.getEfectoR() == false){
			cout << "Oh no! You slid three spaces!" << endl;
			tileO = "S";
			efecto = snek.getEfecto();
			p2.setCasilla(p2.getCasilla() + snek.getEfecto());
			if (p2.getCasilla() < 1){
				p2.setCasilla(1);
			}
			p2.setEfectoR(true);

			this_thread::sleep_for(dura);

			cout << "\nWhich gets you in tile " << p2.getCasilla() << endl;
		}

		else if(tab.getTablero(p2.getCasilla()-1) == "L" && p2.getEfectoR() == false){
			cout << "Woohoo! You climbed three spaces!" << endl;
			tileO = "L";
			efecto = ladd.getEfecto();
			p2.setCasilla(p1.getCasilla() + ladd.getEfecto());
			if (p1.getCasilla() > 30){
				p1.setCasilla(30);
			}
			p2.setEfectoR(true);

			this_thread::sleep_for(dura);

			cout << "\nWhich gets you in tile " << p2.getCasilla() << endl;
		}
		this_thread::sleep_for(dura);

		if(p2.getCasilla() == 30){
			cout << "\nPlayer #2 is the winner" << endl;
			cout << "\n--GAME OVER--" << endl;
			break;
		}

		cout << "\nCurrent player information: " << i << p2.getID() << casO << p2.getNumDado() << tileO << efecto << endl;
		this_thread::sleep_for(dura4);
		
		con.setcon();
		
		if(con.getcon() == false){
			break;
		}

		if(i == 10){
			cout << "\nThe maximum number of turns has been reached..." << endl;
			cout << "\n--GAME OVER--" << endl;
		}

		i = i + 1;
	}
}