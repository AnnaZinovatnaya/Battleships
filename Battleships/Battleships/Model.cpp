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

void Model::pause() 
{
	previousState = state;
	state = PAUSED;
	notify();

	clock_t startTime = clock();
	clock_t endTime = clock();

	int oldTime = 0;
	int newTime = 0;

	while (true)
	{
		endTime = clock();
		newTime = static_cast<int>(endTime - startTime) / CLOCKS_PER_SEC;
		
		if (newTime != oldTime) {

			pauseTime = newTime;
			notify();
			oldTime = newTime;
		}

	}
}

vector<vector<int> > Model::getUserShips()
{
	return user.ships;
}

int Model::getPauseTime() {
	return pauseTime;
}

void Model::endPause()
{
	state = previousState;
	notify();
}
