#include "GameView.h"

GameView::GameView(int numPlayers, int compPlayers, int cardsInHand, bool testing) {
	model = make_shared<GameModel>(numPlayers, compPlayers, cardsInHand, testing, this);
}

void GameView::makeController() {
	controller = make_shared<GameController>(model);
	controller->startGame();
}

//Vector of players, player with special output, cards remaining for special player, vector of heads
bool GameView::printState(vector<shared_ptr<Player>> players, shared_ptr<Player> currPlayer, int cardsToPlay, vector<shared_ptr<Head>> heads) {
	cout << endl << "Heads:" << endl;
	for (auto h : heads) {
		cout << *h << endl;

	}
	cout << endl;
	cout << "Players:" << endl;
	int adjustedSize = 0;
	for (auto p : players) {
		adjustedSize = p->getDraw()->getSize();
		cout << "Player " << p->getPlayerNum() << ": " << adjustedSize + p->getDiscard()->getSize() << " (" << adjustedSize << " draw "
			<< p->getDiscard()->getSize() << " discard)";
		if (currPlayer != nullptr && p->getPlayerNum() == currPlayer->getPlayerNum()) {
			cout << " + 1 in hand, " << cardsToPlay - 1 << " remaining, " << ((currPlayer->getReserve() == nullptr) ? "0" : "1") << " in reserve";
		}
		cout << endl;
	}
		cout << endl;
		return currPlayer != nullptr;
	}


bool GameView::endGame() {
	return model->gameOver();
}
	



void GameView::handleInputs(int player) {
	controller->notify(player);

}