#include "HumanPlayer.h"


HumanPlayer::HumanPlayer(int playerNum) : Player(playerNum) {

}

int HumanPlayer::play(vector<shared_ptr<Head>> h, shared_ptr<Card> c, bool testing) {
	return c->play(testing);
}