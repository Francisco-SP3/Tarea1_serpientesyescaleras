//Francisco Salas Porras A01177893
//Iván López A01284875

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;

class Continue{
//Privadas
	private:
	string con;
//Publicas
	public:
	Continue();
	~Continue();
	bool getcon();
	void setcon();
};

Continue::Continue(){
	con = "";
}

Continue::~Continue(){}

bool Continue::getcon(){
	if(con == "C" || con == "c"){
		return true;
	}
	if(con == "E" || con == "e"){
		return false;
	}
}

void Continue::setcon(){
	while(true){
		cout << "\nPress C to continue next turn, or E to end the game" << endl;
		cin >> con;
    // Continuar con el juego, opción "C"
		if(con == "C" || con == "c"){
			cout << "\nOkay, let's continue..." << endl;
			con = "C";
			chrono::seconds dura(2);
			this_thread::sleep_for(dura);
			break;
		}
    // Terminar con el juego, opción "E"
		if(con == "E" || con == "e"){
			cout << "\nThanks for playing!" << endl;
			con = "E";
			break;
		}
		else{
			cout << "\nYour answer was not valid, please try again" << endl;
		}
	}
}