#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_

#include "Observer.h"
#include "GameView.h"
#include "Player.h"
#include "Strategy.h"


class GameView;

class GameModel {
private:
	int numOfHeads = 1;
	shared_ptr<Player> currPlayer;
	bool testing;
	bool isGameOver = false;
public:
	
	GameView* ob;
	vector<shared_ptr<Player>> players;
	vector<shared_ptr<Head>> heads;
	friend std::ostream& operator<<(std::ostream& out, GameModel& gm);
	GameModel(int numPlayers, int compPlayers,int cardsInHand, bool testing, GameView* o);
	void playTurn(int player, shared_ptr<Card> c, int cardsPlayed, int cardsToPlay);
	bool gameOver();
	void updateView();
	void startGame();

	bool noValidMoves(Card c);


};




#endif