#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "Observer.h"
#include "GameModel.h"
#include <memory>
class GameModel;

class GameController : public Observer {

public:
	GameController(std::shared_ptr<GameModel> m);
	void startGame();
	void handleInputs();
	void notify(int player);

private:
	int currPlayer = 1;
	std::shared_ptr<GameModel> model;
};







#endif