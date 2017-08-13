#include "Model.h"



Model::Model()
{
	srand(time(0));

	user.initialize();
	computer.initialize();

	timeOfGame = 0;
	startTime = 0;
	pauseTime = 0;

	state = INITIALIZED;
	previousState = state;

	endOfGame = false;
}


Model::~Model()
{
}

void Model::attach(Observer* observer)
{
	observers.push_back(observer);
}

void Model::detach(Observer* observer)
{
	observers.remove(observer);
}

void Model::notify()
{
	for (Observer* observer : observers) {
		observer->update();
	}
}

stateType Model::getState()
{
	return state;
}



void Model::play()
{
	startTime = clock();
	state = STARTED;
	notify();
}

bool Model::checkEndOfGame()
{
	return false;
}



vector<vector<int> > Model::getUserShips()
{
	return user.ships;
}



void Model::hit(vector<int> userHit)
{
	user.hit(userHit);

	state = COMPUTER_TURN;

	bool isComputerShipSunk = computer.markSunkShips(user.hits);

	if (isComputerShipSunk)
	{
		endOfGame = checkEndOfGame();
	}

	if (endOfGame)
		state = ENDED;

	notify();
}

bool Model::isUserDefeat()
{
	return user.getIsDeafeat();
}

int Model::getTimeOfGame()
{
	return timeOfGame;
}

int Model::countComputerSunkShips()
{
	return computer.countSunkShips();
}

int Model::countUserSunkShips()
{
	return user.countSunkShips();
}
