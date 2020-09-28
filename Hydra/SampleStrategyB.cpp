#include "SampleStrategyB.h"
#include <climits>

int StrategyB::excecuteAlgorithm(vector<shared_ptr<Head>> h, shared_ptr<Card> c) { // Sample Strategy to Play on Highest head
	int highestIndex = 0;
	int highCard = INT_MIN;
	for (int i = 0; i < h.size(); i++) {
		if (Head::stringToVal(h.at(i)->topCard()->getValue()) > highCard && h.at(i)->validMove(*c)) {
			highestIndex = i;
			highCard = Head::stringToVal(h.at(i)->topCard()->getValue());
		}
	}
	return highestIndex + h.at(0)->getHeadNumber();
}