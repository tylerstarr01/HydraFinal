#include "Deck.h"

class Head : public Deck {
private:
	int headNum;
public:
	Head(int number);
	virtual std::shared_ptr<Card> topCard() override;
	int getHeadNumber();
	bool validMove(Card c);
	static int stringToVal(string l);

};

ostream& operator<< (ostream& out, Head& h);