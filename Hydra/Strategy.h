#ifndef STRATEGY_H_
#define STRATEGY_H_
#include "Player.h"
#include <vector>
#include <memory>
using namespace std;

class Strategy {
public:
	virtual int excecuteAlgorithm(vector<shared_ptr<Head>> h, shared_ptr<Card> c) { return 0; }

};

#endif