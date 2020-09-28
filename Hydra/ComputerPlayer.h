#ifndef COMPUTER_H_
#define COMPUTER_H_
#include "Player.h"
#include "Strategy.h"
#include "SampleStrategyA.h"
#include "HumanPlayer.h"
#include <memory>

class ComputerPlayer : public Player {

private:

	shared_ptr<Strategy> currStrat = make_shared<StrategyA>(); // Strategy A is the default strategy, can be changed later
public:
	ComputerPlayer(shared_ptr<Strategy> s, int number);
	ComputerPlayer(shared_ptr<Player> h); //Convert Human to Computer Player
	int play(vector<shared_ptr<Head>> h, shared_ptr<Card> c, bool testing) override;
	void changeStrategy(shared_ptr<Strategy> s);

};



#endif