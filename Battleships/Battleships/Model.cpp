#include "Model.h"



Model::Model()
{
	srand(time(0));

	human.initialize();
	computer.initialize();

	timeOfGame = 0;
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

void Model::getData()
{
}

void Model::service()
{
	//actions
	notify();
}

void Model::play()
{
}

bool Model::checkEndOfGame()
{
	return false;
}

void Model::pause() const
{
}
