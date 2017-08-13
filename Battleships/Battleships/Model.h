#ifndef Model_h__
#define Model_h__

#include <list>
#include <vector>
using namespace std;

#include "Observer.h"
#include "Map.h"
#include "Player.h"
#include "ComputerPlayer.h"

enum stateType {INITIALIZED, STARTED, USER_TURN, COMPUTER_TURN, ENDED, PAUSED};

class Model
{
public:
	list <Observer*> observers;
	
	stateType state;
	stateType previousState;
	int pauseTime;

	Player user;
	ComputerPlayer computer;
	int timeOfGame;
	clock_t startTime;

	bool endOfGame;


	Model();
	~Model();

	void attach(Observer* observer);
	void detach(Observer* observer);

	void notify();
	stateType getState();

	void play();
	bool checkEndOfGame();

	vector<vector<int>> getUserShips();
	vector<vector<int>> getComputerShips();

	vector<vector<int>> getUserHits();
	vector<vector<int>> getComputerHits();
	
	void hit(vector<int> userHit);

	bool isUserDefeat();
	
	int getTimeOfGame();

	int countComputerSunkShips();

	int countUserSunkShips();
	
};

#endif

