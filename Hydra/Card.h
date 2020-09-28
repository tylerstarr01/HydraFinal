#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <iostream>
using namespace std;

class Card {
private:
	string suit;
	string value;
public:
	Card(string suit, string value);
	string getSuit();
	string getValue();
	void setValue(string v);
	virtual string getString();
	virtual int play(bool testing);
	


};

std::ostream& operator<< (std::ostream& out, Card& s);

#endif