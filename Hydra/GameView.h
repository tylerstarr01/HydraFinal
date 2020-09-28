#ifndef GAMEVIEW_H_
#define GAMEVIEW_H_
#include "Observer.h"
#include "GameController.h"
#include "GameModel.h"
#include "Player.h"

class GameModel;
class GameController;
using namespace std;

class GameView : public Observer{
private:
	shared_ptr<GameModel> model;
	shared_ptr<GameController> controller;
	

public:
	GameView(int numPlayers, int compPlayers, int cardsInHand, bool testing);
	void makeController();
	bool endGame();
	bool printState(vector<shared_ptr<Player>> players, shared_ptr<Player> currPlayer, int cardsToPlay, vector<shared_ptr<Head>> heads);
	void handleInputs(int player);
	

};

#endif
