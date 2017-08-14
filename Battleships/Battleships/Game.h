#ifndef Game_h__
#define Game_h__

#include <list>
#include <vector>
using namespace std;

#include "Observer.h"
#include "Player.h"
#include "ComputerPlayer.h"

enum stateType {INITIALIZED, STARTED, USER_TURN, COMPUTER_TURN, ENDED, PAUSED};

class Game
{
  public:
    Game();
    ~Game();

    void attach(Observer* observer);
    void detach(Observer* observer);

    stateType getState() const;

    void play();

    vector<vector<int>> getUserShips() const;
    vector<vector<int>> getComputerShips() const;

    vector<vector<int>> getUserHits() const;
    vector<vector<int>> getComputerHits() const;

    int getTimeOfGame() const;

    void hit(vector<int> userHit);

    bool isUserDefeat() const;

    int countComputerSunkShips() const;
    int countUserSunkShips() const;
  private:
    list <Observer*> observers;

    stateType state;
    stateType previousState;

    Player user;
    ComputerPlayer computer;

    int timeOfGame;
    clock_t startTime;

    void notify();
    bool checkEndOfGame() const;
};

#endif

