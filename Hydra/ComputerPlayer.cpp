#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(shared_ptr<Strategy> s, int number) : Player(number) {
	this->currStrat = s;
}

ComputerPlayer::ComputerPlayer(shared_ptr<Player> h) : Player(h->getPlayerNum()){
	for (int i = 0; i < h->getDiscard()->getSize(); i++) {
		this->getDiscard()->add(h->getDiscard()->topCard());
	}
	for (int i = 0; i < h->getDraw()->getSize(); i++) {
		this->getDraw()->add(h->getDraw()->topCard());
	}
	if (h->getReserve() != nullptr) {
		this->setReserve(h->getReserve());
	}
}

int ComputerPlayer::play(vector<shared_ptr<Head>> h, shared_ptr<Card> c, bool testing) {
	cout << ", you are holding a " << c->getString() << endl;
	return currStrat->excecuteAlgorithm(h, c);
}
void ComputerPlayer::changeStrategy(shared_ptr<Strategy> s) {
	this->currStrat = s;
}