#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include "Player.h"

class HumanPlayer : public Player {

public:
	HumanPlayer(int playerNumber);
	int play(vector<shared_ptr<Head>> h, shared_ptr<Card> c, bool testing) override;

};



#endif