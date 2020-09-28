#include "Player.h"

Player::Player(int i) {
	draw = make_shared<Deck>();
	discard = make_shared<Deck>();
	reserve = nullptr;
	playerNumber = i;
}

shared_ptr<Card> Player::makeMove() {
	return this->getDraw()->topCard();
}

int Player::getPlayerNum() {
	return playerNumber;
}

shared_ptr<Deck> Player::getDraw() {
	return draw;
}
shared_ptr<Deck> Player::getDiscard() {
	return discard;
}
shared_ptr<Card> Player::getReserve() {
	return reserve;
}

void Player::setReserve(shared_ptr<Card> r) {
	this->reserve = r;
}

void Player::discardToDraw() {
	for (int i = 0; i < this->getDiscard()->getSize(); i++) {
		this->getDraw()->add(this->getDiscard()->topCard());
	}
	this->getDraw()->shuffle();

}



