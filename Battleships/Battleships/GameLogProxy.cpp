#include "GameLogProxy.h"



GameLogProxy::GameLogProxy(Game game)
{
	this->game = game;
	this->logFile.open("logs.txt");
}


GameLogProxy::~GameLogProxy()
{
	this->logFile.close();
}

void GameLogProxy::attach(Observer * observer)
{
	logFile << "GameLogProxy::attach()" << std::endl;
	game.attach(observer);
}

void GameLogProxy::detach(Observer * observer)
{
	logFile << "GameLogProxy::detach()" << std::endl;
	game.detach(observer);
}

stateType GameLogProxy::getState() 
{
	stateType state = game.getState();
	logFile << "GameLogProxy::getState() - state " << state << std::endl;
	return state;
}

void GameLogProxy::play()
{
	logFile << "GameLogProxy::play()" << std::endl;
	game.play();
}

vector<vector<int>> GameLogProxy::getUserShips() 
{
	logFile << "GameLogProxy::getUserShips()" << std::endl;
	return game.getUserShips();
}

vector<vector<int>> GameLogProxy::getComputerShips() 
{
	logFile << "GameLogProxy::getComputerShips()" << std::endl;
	return game.getComputerShips();
}

vector<vector<int>> GameLogProxy::getUserHits() 
{
	logFile << "GameLogProxy::getUserHits()" << std::endl;
	return game.getUserHits();
}

vector<vector<int>> GameLogProxy::getComputerHits() 
{
	logFile << "GameLogProxy::getComputerHits()" << std::endl;
	return game.getComputerHits();
}

int GameLogProxy::getTimeOfGame() 
{
	int time = game.getTimeOfGame();
	logFile << "GameLogProxy::getTimeOfGame() - time " << time << std::endl;
	return time;
}

void GameLogProxy::hit(vector<int> userHit)
{
	logFile << "GameLogProxy::hit() - hit " << userHit.at(0) << " " << userHit.at(1) << std::endl;
	game.hit(userHit);
}

bool GameLogProxy::isUserDefeat() 
{
	bool value = game.isUserDefeat();
	logFile << "GameLogProxy::isUserDefeat() - value " << value << std::endl;
	return value;
}

int GameLogProxy::countComputerSunkShips() 
{
	int value = game.countComputerSunkShips();
	logFile << "GameLogProxy::countComputerSunkShips() - value " << value << std::endl;
	return value;
}

int GameLogProxy::countUserSunkShips() 
{
	int value = game.countUserSunkShips();
	logFile << "GameLogProxy::countUserSunkShips() - value " << value << std::endl;
	return value;
}

void GameLogProxy::pause()
{
	logFile << "GameLogProxy::pause()" << std::endl;
	game.pause();
}

clock_t GameLogProxy::getPauseStartTime() 
{
	clock_t time = game.getPauseStartTime();
	logFile << "GameLogProxy::getPauseStartTime() - time " << time << std::endl;
	return time;
}

void GameLogProxy::stopPause()
{
	logFile << "GameLogProxy::stopPause()" << std::endl;
	game.stopPause();
}

bool GameLogProxy::getIsComputerShipSunk() 
{
	bool value = game.getIsComputerShipSunk();
	logFile << "GameLogProxy::getIsComputerShipSunk() - value " << value << std::endl;
	return value;
}
