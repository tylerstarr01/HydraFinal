#include "Head.h"

Head::Head(int number) {
	headNum = number;
}

std::shared_ptr<Card> Head::topCard() {
	return cards.back();
}

int Head::getHeadNumber() {
	return headNum;
}

int Head::stringToVal(string l) {
	int left;
	if (l == "A") {
		left = 1;
	}
	else if (l == "J") {
		left = 11;
	}
	else if (l == "Q") {
		left = 12;
	}
	else if (l == "K") {
		left = 13;
	}
	else {
		left = stoi(l);
	}
	return left;
}

bool Head::validMove(Card c) {
	if (topCard()->getValue() == "A") {
		return true;
	} else {
		return stringToVal(c.getValue()) <= stringToVal(topCard()->getValue());
	}
}

ostream& operator<< (ostream& out, Head& h) { 
	shared_ptr<Card> temp = h.topCard();
	out << h.getHeadNumber() << ": " << temp->getValue() +  temp->getSuit() << " (" << h.getSize() << ")";
	return out;
}