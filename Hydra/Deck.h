#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <vector>
#include <memory>
#include <algorithm>

class Deck {

private:
	
	int size = 0;

public:
	std::vector<std::shared_ptr<Card>> cards;
	int getSize();
	virtual std::shared_ptr<Card> topCard();
	void shuffle();
	bool deckEmpty();
	void add(std::shared_ptr<Card> c);
	

};




#endif





