#ifndef Game_h__
#define Game_h__

#include <list>
#include <vector>
using namespace std;

#include "Observer.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "IGame.h"

class Game :
	IGame
{
  public:
    Game();
    ~Game();

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
    list <Observer*> observers;

    stateType state;
    stateType previousState;

    Player user;
    ComputerPlayer computer;

    int timeOfGame;
    clock_t startTime;

	clock_t pauseStartTime;

	bool isComputerShipSunk;

    void notify();

    bool checkEndOfGame() const;
};

#endif

