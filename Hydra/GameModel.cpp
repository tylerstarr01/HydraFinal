
#include "GameModel.h"
#include "Joker.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "SampleStrategyB.h"


GameModel::GameModel(int numPlayers, int compPlayers, int cardsInHand, bool testing, GameView* o) {
	this->testing = testing;
	Deck d{};
	std::vector<string> vec = { "H", "D", "C", "S" };
	std::vector<string> nums = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	d.add(make_shared<Card>("D", "K"));
	for (int i = 0; i < numPlayers + compPlayers; i++) {
		d.add(make_shared<Joker>());
		d.add(make_shared<Joker>());
		for (auto n : nums) {
			for (auto c : vec) {
				d.add(make_shared<Card>(c, n));
				//d.add(make_shared<Joker>());
			}
		}
	}
	d.shuffle();
	int cardsForHand = cardsInHand;
	for (int i = 0; i < numPlayers; i++) {
		shared_ptr<Player> p = make_shared<HumanPlayer>(i + 1);
		this->players.emplace_back(p);
		for (int i = 0; i < cardsForHand; i++) {
			p->draw->add(d.topCard());
			
		}
	}
	for (int i = 0; i < compPlayers; i++) {
		shared_ptr<Player> p = make_shared<ComputerPlayer>(make_shared<StrategyB>(), i + 1 + numPlayers);
		this->players.emplace_back(p);
		for (int i = 0; i < cardsForHand; i++) {
			p->draw->add(d.topCard());
		}
	}
	heads.emplace_back(make_shared<Head>(numOfHeads));
	++numOfHeads;
	currPlayer = players.at(0);
	this->ob = o;
}


void GameModel::startGame() {
	shared_ptr<Card> card = players.at(0)->getDraw()->topCard();
	heads.at(0)->add(card);
	//cout << *heads.at(0) << endl;
	
}


bool GameModel::noValidMoves(Card c) {
	for (auto h : this->heads) {
		if (h->validMove(c)) {
			return false;
		}
	}
	return true;
}

bool GameModel::gameOver() {
	return isGameOver;
}

void GameModel::playTurn(int player, shared_ptr<Card> c, int cardsPlayed, int cardsToPlay) {
	if (cardsPlayed == cardsToPlay) {
		currPlayer->getDraw()->add(c);
		//End Turn
		return;
	}
	if (currPlayer->getDraw()->getSize() == 0 && currPlayer->getDiscard()->getSize() == 0) {
		// Game Over
		cout << "Player " << player << " wins!" << endl;
		isGameOver = true;
		return;
	} else if (currPlayer->getDraw()->getSize() == 0) {
		currPlayer->discardToDraw();
	}
	currPlayer = players.at(player - 1);
	ob->printState(players, currPlayer, cardsToPlay - cardsPlayed, heads);
	cout << "Player " << player;
	int indexEntered = currPlayer->play(heads, c, testing);
	int headIndex = indexEntered - heads.front()->getHeadNumber();
	if (indexEntered == -1) {
		players.at(player - 1) = make_shared<ComputerPlayer>(currPlayer);
		currPlayer = players.at(player - 1);
	} else if (indexEntered == 0) {
		// Swap Reserve Card
		if (currPlayer->getReserve() != nullptr) {
			shared_ptr<Card> temp = currPlayer->getReserve();
			currPlayer->setReserve(c);
			playTurn(player, temp, cardsPlayed, cardsToPlay);
			return;
		} else {
			currPlayer->setReserve(c);
		}
	}
	else if (noValidMoves(*c)) {
		if (headIndex == 0) {
			currPlayer->getDiscard()->add(c);
			for (int i = 0; i < heads.at(0)->getSize(); i++) {
				currPlayer->getDiscard()->add(heads.at(0)->cards.at(i));
			}
			if (currPlayer->getReserve() != nullptr) {
				currPlayer->getDiscard()->add(currPlayer->getReserve());
			}
			currPlayer->getDiscard()->shuffle();
			currPlayer->getReserve() = nullptr;
			heads.erase(heads.begin());
			if (currPlayer->getDraw()->getSize() < 2 && currPlayer->getDiscard()->getSize() > 2 - currPlayer->getDraw()->getSize()) {
				currPlayer->discardToDraw();
			}
			int combinedSize = currPlayer->getDraw()->getSize() + currPlayer->getDiscard()->getSize();
			int newHeads = combinedSize >= 2 ? 2 : combinedSize;
			for (int i = 0; i < newHeads; i++) {
				heads.emplace_back(make_shared<Head>(numOfHeads++));
				heads.back()->add(currPlayer->getDraw()->topCard());
			}			
		}
		else {
			playTurn(player, c, cardsPlayed, cardsToPlay); // Re-prompt user
			return;
		}
	}
	else if (headIndex < 0 || headIndex >= heads.size() || !heads.at(headIndex)->validMove(*c)) {
		playTurn(player, c, cardsPlayed, cardsToPlay); // Re-prompt user
		return;
	}
	else { // Valid Move
		shared_ptr<Card> temp = heads.at(headIndex)->topCard();
		heads.at(headIndex)->add(c);
		if (temp->getValue() == c->getValue()) {			
			return; // End turn if card is equal to top card on head
		}
	}
	if (currPlayer->getDraw()->getSize() == 0 && currPlayer->getDiscard()->getSize() == 0) {
		cout << "Player " << player << " wins" << endl;
		isGameOver = true;
		return;
	}  else if (currPlayer->getDraw()->getSize() == 0) {
		currPlayer->discardToDraw();
	}
	cardsPlayed++;
	playTurn(player, currPlayer->makeMove(), cardsPlayed, cardsToPlay);

	
}

void GameModel::updateView() {
	this->ob->nofify();
}

std::ostream& operator<<(std::ostream& out, GameModel& gm) {
	for (auto p : gm.players) {
		out << "Player " << p->getPlayerNum() << ": " << p->getDraw()->getSize() + p->getDiscard()->getSize() << " (" << p->getDraw()->getSize() << " draw " << p->getDiscard()->getSize() << " discard" 
			<< ") " << std::endl;
	}
	return out;
}



