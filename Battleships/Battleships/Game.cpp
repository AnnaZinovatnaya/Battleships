#include "Game.h"



Game::Game()
{
	srand(time(0));

	user.initialize();
	computer.initialize();

	timeOfGame = 0;
	startTime = 0;

	state = INITIALIZED;
	previousState = state;
}


Game::~Game()
{
}

void Game::attach(Observer* observer)
{
	observers.push_back(observer);
}

void Game::detach(Observer* observer)
{
	observers.remove(observer);
}

void Game::notify()
{
	for (Observer* observer : observers) {
		observer->update();
	}
}

stateType Game::getState() const
{
	return state;
}



void Game::play()
{
	startTime = clock();
	state = STARTED;
	notify();
}

bool Game::checkEndOfGame() const
{
	bool humanShipsKilled = user.checkDefeat();
	if (humanShipsKilled)
		return true;

	bool computerShipsKilled = computer.checkDefeat();
	if (computerShipsKilled)
		return true;

	return false;
}



vector<vector<int> > Game::getUserShips() const
{
	return user.getShips();
}

vector<vector<int>> Game::getComputerShips() const
{
	return computer.getShips();
}

vector<vector<int>> Game::getUserHits() const
{
	return user.getHits();
}

vector<vector<int>> Game::getComputerHits() const
{
	return computer.getHits();
}



void Game::hit(vector<int> userHit)
{
	user.hit(userHit);

	state = COMPUTER_TURN;

	notify();

	bool endOfGame = false;

	bool isComputerShipSunk = computer.markSunkShips(user.getHits());

	if (isComputerShipSunk)
	{
		endOfGame = checkEndOfGame();
	}

	if (endOfGame) {

		timeOfGame = static_cast<int>(clock() - startTime) / CLOCKS_PER_SEC;
		state = ENDED;
		notify();

	}else{
		computer.hit();


		bool isAnyHumanShipHit = user.isAnyShipHit(computer.getLastHitX(),
			computer.getLastHitY());

		if (isAnyHumanShipHit)
		{
			computer.markSuccessHit();

			bool isHumanShipSunk = user.markSunkShips(computer.getHits());
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

			timeOfGame = static_cast<int>(clock() - startTime) / CLOCKS_PER_SEC;

			notify();
		}
		else {

			state = USER_TURN;
			notify();
		}
	}
}

bool Game::isUserDefeat() const
{
	return user.checkDefeat();
}

int Game::getTimeOfGame() const
{
	return timeOfGame;
}

int Game::countComputerSunkShips() const
{
	return computer.countSunkShips();
}

int Game::countUserSunkShips() const
{
	return user.countSunkShips();
}


