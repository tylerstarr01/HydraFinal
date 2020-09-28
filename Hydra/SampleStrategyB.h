#ifndef STRATEGYB_H_
#define STRATEGYB_H_


#include "Strategy.h"

class StrategyB : public Strategy {

public:
    int excecuteAlgorithm(vector<shared_ptr<Head>> h, shared_ptr<Card> c) override;

};

#endif