//Francisco Salas Porras A01177893

#include <iostream>
#include <stdlib.h>
#include "Players.h"
using namespace std;


class Continue{
	private:
	string con;

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
		cout << "Press C to continue next turn, or E to end the game" << endl;
		cin >> con;
		if(con == "C" || con == "c"){
			cout << "Okay, let's continue" << endl;
			con = "C";
      players.SetID();
			break;
		}
		if(con == "E" || con == "e"){
			cout << "Okay, see you later!" << endl;
			con = "E";
			break;
		}
		else{
			cout << "Your answer was not valid, please try again" << endl;
		}
	}
}