#ifndef IGame_h__
#define IGame_h__

#include <ctime>
#include <vector>
using namespace std;

#include "Observer.h"

enum stateType { INITIALIZED, STARTED, USER_TURN, COMPUTER_TURN, ENDED, PAUSED };

class IGame
{
public:
	IGame();
	virtual ~IGame();

	virtual void attach(Observer* observer) = 0;
	virtual void detach(Observer* observer) = 0;

	virtual stateType getState() = 0;

	virtual void play() = 0;

	virtual vector<vector<int> > getUserShips() = 0;
	virtual vector<vector<int> > getComputerShips() = 0;

	virtual vector<vector<int> > getUserHits() = 0;
	virtual vector<vector<int> > getComputerHits() = 0;

	virtual int getTimeOfGame() = 0;

	virtual void hit(vector<int> userHit) = 0;

	virtual bool isUserDefeat() = 0;

	virtual int countComputerSunkShips() = 0;
	virtual int countUserSunkShips() = 0;

	virtual void pause() = 0;

	virtual clock_t getPauseStartTime() = 0;

	virtual void stopPause() = 0;

	virtual bool getIsComputerShipSunk() = 0;
};
#endif
