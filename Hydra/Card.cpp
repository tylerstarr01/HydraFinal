#include "Card.h"
#include "GameModel.h"


Card::Card(string suit, string value) {
	this->suit = suit;
	this->value = value;
}

string Card::getSuit() {
	return this->suit;
}
string Card::getValue() {
	return this->value;
}
std::string Card::getString() {
	return this->getValue() + this->getSuit();
}

void Card::setValue(string v) {
	this->value = v;
}

int Card::play(bool testing) {
	if (testing) {
		cout << ", you are holding a..." << endl << "Card Value?" << endl;
		string val;
		getline(cin, val);
		setValue(val);
		string suit;
		cout << "Suit Value" << endl;
		getline(cin, suit);
		this->suit = suit;
	}
	string headNum;
	cout << *this;
	getline(cin, headNum);
	return stoi(headNum);
}



std::ostream& operator<< (std::ostream& out, Card& s) {
	out << ", you are holding a " << s.getString() << ". Your move?" << std::endl;
	return out;
}
