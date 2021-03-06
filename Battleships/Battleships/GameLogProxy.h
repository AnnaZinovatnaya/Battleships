#ifndef GameLogProxy_h__
#define GameLogProxy_h__

#include "IGame.h"
#include "Game.h"

#include <fstream>
#include <ctime>

class GameLogProxy :
	public IGame
{
public:
	GameLogProxy(Game game);
	~GameLogProxy();

	void attach(Observer* observer);
	void detach(Observer* observer);

	stateType getState();

	void play();

	vector<vector<int>> getUserShips();
	vector<vector<int>> getComputerShips();

	vector<vector<int>> getUserHits();
	vector<vector<int>> getComputerHits();

	int getTimeOfGame();

	void hit(vector<int> userHit);

	bool isUserDefeat();

	int countComputerSunkShips();
	int countUserSunkShips();

	void pause();

	clock_t getPauseStartTime();

	void stopPause();

	bool getIsComputerShipSunk();
private:
	Game game;
	std::ofstream logFile;
	char time[10];
	void logTime();
};
#endif

