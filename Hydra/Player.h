#ifndef PLAYER_H_
#define PLAYER_H_
#include "Head.h"

class Player {

private:
	shared_ptr<Card> reserve;
	
	shared_ptr<Deck> discard;
	int playerNumber;
public:
	Player(int num);
	shared_ptr<Card> makeMove();
	shared_ptr<Deck> draw;
	int getPlayerNum();
	shared_ptr<Deck> getDraw();
	shared_ptr<Deck> getDiscard();
	shared_ptr<Card> getReserve();
	void setReserve(shared_ptr<Card> r);
	void discardToDraw();
	virtual int play(vector<shared_ptr<Head>> h, shared_ptr<Card> c, bool testing) { return 0; }
};



#endif