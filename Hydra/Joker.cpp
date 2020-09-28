#include "Joker.h"

Joker::Joker() : Card("J", "2") {}

std::string Joker::getString() {
	return "Joker";
}



int Joker::play(bool testing) {
	cout << *this;
	string headNum;
	getline(cin, headNum);
	cout << "Joker Value? " << std::endl;
	string val;
	getline(cin, val);
	//cin >> val;
	this->setValue(val);
	return stoi(headNum);
	
	// Prompt user to select value of Joker
}

