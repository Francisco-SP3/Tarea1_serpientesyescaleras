//Francisco Salas Porras A01177893

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Players.h"
using namespace std;

class Continue{
//Privadas
	private:
	string con;
//Publicas
	public:
  Players players;
	Continue();
	~Continue();
	string getcon();
	void setcon();
};

Continue::Continue(){
	con = "";
}

Continue::~Continue(){}

string Continue::getcon(){
	return con;
}

void Continue::setcon(){
	while(true){
		cout << "\nPress C to continue next turn, or E to end the game" << endl;
		cin >> con;
		if(con == "C" || con == "c"){
			cout << "\nOkay, let's continue..." << endl;
			con = "C";
			chrono::seconds dura(2);
			this_thread::sleep_for(dura);
      players.SetID();
			break;
		}
		if(con == "E" || con == "e"){
			cout << "\nOkay, see you later!" << endl;
			con = "E";
			break;
		}
		else{
			cout << "\nYour answer was not valid, please try again" << endl;
		}
	}
}