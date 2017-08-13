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
	bool humanShipsKilled = user.checkEndOfGame();
	if (humanShipsKilled)
		return true;

	bool computerShipsKilled = computer.checkEndOfGame();
	if (computerShipsKilled)
		return true;

	return false;
}



vector<vector<int> > Model::getUserShips()
{
	return user.ships;
}

vector<vector<int>> Model::getComputerShips()
{
	return computer.ships;
}

vector<vector<int>> Model::getUserHits()
{
	return user.hits;
}

vector<vector<int>> Model::getComputerHits()
{
	return computer.hits;
}



void Model::hit(vector<int> userHit)
{
	user.hit(userHit);

	state = COMPUTER_TURN;

	notify();

	bool isComputerShipSunk = computer.markSunkShips(user.hits);

	if (isComputerShipSunk)
	{
		endOfGame = checkEndOfGame();
	}

	if (endOfGame) {

		state = ENDED;
		notify();

	}else{
		computer.hit();


		bool isAnyHumanShipHit = user.isAnyShipHit(computer.getLastHitX(),
			computer.getLastHitY());

		if (isAnyHumanShipHit)
		{
			computer.markSuccessHit();

			bool isHumanShipSunk = user.markSunkShips(computer.hits);
			if (isHumanShipSunk)
			{
				computer.markSunkShip();
				endOfGame = checkEndOfGame();
			}
		}
		else
		{
			computer.markMissedHit();
		}

		if (endOfGame) {
			state = ENDED;
			notify();
		}
		else {

			state = USER_TURN;
			notify();
		}
	}
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
