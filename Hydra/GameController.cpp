#include "GameController.h"

GameController::GameController(shared_ptr<GameModel> m) {
	this->model = m;
}

void GameController::handleInputs() {

}
void GameController::notify(int player) {
	int cardsToPlay = model->heads.size();
	model->ob->printState(model->players, nullptr, 0, model->heads);
	shared_ptr<Card> c = model->players.at(player - 1)->makeMove();
	string nothing;
	cout << "Player " << player << ", it is your turn." << endl;
	std::getline(cin, nothing);
	if (nothing == "-1") {
		
	}
	model->playTurn(player, c, 0, cardsToPlay);
	if (model->players.at(player - 1)->getReserve() != nullptr) {
		model->players.at(player - 1)->getDraw()->add(model->players.at(player - 1)->getReserve());
	}
	model->players.at(player - 1)->setReserve(nullptr);
}



void GameController::startGame() {
	model->startGame();
}
