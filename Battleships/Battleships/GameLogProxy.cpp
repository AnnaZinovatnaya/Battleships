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
	logTime();
	logFile << "GameLogProxy::attach()" << std::endl;
	game.attach(observer);
}

void GameLogProxy::detach(Observer * observer)
{
	logTime();
	logFile << "GameLogProxy::detach()" << std::endl;
	game.detach(observer);
}

stateType GameLogProxy::getState() 
{
	logTime();
	stateType state = game.getState();
	logFile << "GameLogProxy::getState() - state " << state << std::endl;
	return state;
}

void GameLogProxy::play()
{
	logTime();
	logFile << "GameLogProxy::play()" << std::endl;
	game.play();
}

vector<vector<int>> GameLogProxy::getUserShips() 
{
	logTime();
	logFile << "GameLogProxy::getUserShips()" << std::endl;
	return game.getUserShips();
}

vector<vector<int>> GameLogProxy::getComputerShips() 
{
	logTime();
	logFile << "GameLogProxy::getComputerShips()" << std::endl;
	return game.getComputerShips();
}

vector<vector<int>> GameLogProxy::getUserHits() 
{
	logTime();
	logFile << "GameLogProxy::getUserHits()" << std::endl;
	return game.getUserHits();
}

vector<vector<int>> GameLogProxy::getComputerHits() 
{
	logTime();
	logFile << "GameLogProxy::getComputerHits()" << std::endl;
	return game.getComputerHits();
}

int GameLogProxy::getTimeOfGame() 
{
	int time = game.getTimeOfGame();
	logTime();
	logFile << "GameLogProxy::getTimeOfGame() - time " << time << std::endl;
	return time;
}

void GameLogProxy::hit(vector<int> userHit)
{
	logTime();
	logFile << "GameLogProxy::hit() - hit " << userHit.at(0) << " " << userHit.at(1) << std::endl;
	game.hit(userHit);
}

bool GameLogProxy::isUserDefeat() 
{
	bool value = game.isUserDefeat();
	logTime();
	logFile << "GameLogProxy::isUserDefeat() - value " << value << std::endl;
	return value;
}

int GameLogProxy::countComputerSunkShips() 
{
	int value = game.countComputerSunkShips();
	logTime();
	logFile << "GameLogProxy::countComputerSunkShips() - value " << value << std::endl;
	return value;
}

int GameLogProxy::countUserSunkShips() 
{
	int value = game.countUserSunkShips();
	logTime();
	logFile << "GameLogProxy::countUserSunkShips() - value " << value << std::endl;
	return value;
}

void GameLogProxy::pause()
{
	logTime();
	logFile << "GameLogProxy::pause()" << std::endl;
	game.pause();
}

clock_t GameLogProxy::getPauseStartTime() 
{
	clock_t time = game.getPauseStartTime();
	logTime();
	logFile << "GameLogProxy::getPauseStartTime() - time " << time << std::endl;
	return time;
}

void GameLogProxy::stopPause()
{
	logTime();
	logFile << "GameLogProxy::stopPause()" << std::endl;
	game.stopPause();
}

bool GameLogProxy::getIsComputerShipSunk() 
{
	bool value = game.getIsComputerShipSunk();
	logTime();
	logFile << "GameLogProxy::getIsComputerShipSunk() - value " << value << std::endl;
	return value;
}

void GameLogProxy::logTime()
{
	_strtime_s(time);
	logFile << time << "\t";
}
