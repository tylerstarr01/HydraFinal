#ifndef STRATEGYA_H_
#define STRATEGYA_H_


#include "Strategy.h"

class StrategyA : public Strategy {

public:
    
    int excecuteAlgorithm(vector<shared_ptr<Head>> h, shared_ptr<Card> c) override;


};

#endif