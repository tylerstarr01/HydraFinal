#include "SampleStrategyA.h"
#include <climits>

int StrategyA::excecuteAlgorithm(vector<shared_ptr<Head>> h, shared_ptr<Card> c) { // Sample Strategy to Play on Lowest head
	int lowestIndex = 0;
	int lowCard = INT_MAX;
	for (int i = 0; i < h.size(); i++) {
		if (Head::stringToVal(h.at(i)->topCard()->getValue()) < lowCard && h.at(i)->validMove(*c)) {
			lowestIndex = i;
			lowCard = Head::stringToVal(h.at(i)->topCard()->getValue());
		}
	}
	return lowestIndex + h.at(0)->getHeadNumber();
}