#include "Deck.h"
#include <time.h>


int Deck::getSize() {
	return this->size;
}
std::shared_ptr<Card> Deck::topCard() {
	//cout << "Curr Deck Size is: " << cards.size();
	if (!deckEmpty()) {
	//cout << cards.size() << endl;
		shared_ptr<Card> c = cards.back();
		size--;
		cards.pop_back();
		return c;
	} else {
		throw;
	}



}

bool Deck::deckEmpty() {
	return cards.size() == 0;
}

void Deck::shuffle() {
	int size = this->cards.size();
	if (size == 1) {
		return;
	}
	int randIndex;
	srand(time(NULL));
	std::shared_ptr<Card> temp;
	for (int i = 0; i < size; i++) {
		randIndex = rand() % (size - 1);
		temp = cards.at(randIndex);
		cards.at(randIndex) = cards.at(i);
		cards.at(i) = temp;
	}
}

void Deck::add(std::shared_ptr<Card> c) {
	this->cards.emplace_back(c);
	size++;
}


