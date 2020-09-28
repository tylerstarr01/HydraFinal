#ifndef JOKER_H_
#define JOKER_H_
#include <string>
#include "Card.h"

class Joker : public Card {

private:
	string value;
	string suit;
public:
	Joker();
	string getString() override;
	int play(bool testing) override;


};



#endif