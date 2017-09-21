#include "Game.h"



Game::Game()
{
  srand(time(0));

  user.initialize();
  computer.initialize();

  timeOfGame = 0;
  startTime = 0;

  pauseStartTime = 0;

  state = INITIALIZED;
  previousState = state;

  isComputerShipSunk = false;
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

  previousState = state;
  state = COMPUTER_TURN;

  bool endOfGame = false;

  computer.markSunkShips(user.getHits());
  isComputerShipSunk = computer.isAnyShipSunk();
  notify();
  if (isComputerShipSunk) {
    endOfGame = checkEndOfGame();
  }

  if (endOfGame) {
    timeOfGame = static_cast<int>(clock() - startTime) / CLOCKS_PER_SEC;
    state = ENDED;
    notify();
  }
  else {
    computer.hit();

    bool isAnyHumanShipHit = user.isAnyShipHit(computer.getLastHitX(),
                             computer.getLastHitY());

    if (isAnyHumanShipHit) {
      computer.markSuccessHit();

	  user.markSunkShips(computer.getHits());
      bool isHumanShipSunk = user.isAnyShipSunk();
      if (isHumanShipSunk) {
        computer.markSunkShip();
        endOfGame = checkEndOfGame();
      }
    }
    else {
      computer.markMissedHit();
    }

    if (endOfGame) {
	  previousState = state;
      state = ENDED;

      timeOfGame = static_cast<int>(clock() - startTime) / CLOCKS_PER_SEC;

      notify();
    }
    else {
	  previousState = state;
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



void Game::pause()
{
	pauseStartTime = clock();
	previousState = state;
	state = PAUSED;
	notify();
}

clock_t Game::getPauseStartTime() const
{
	return pauseStartTime;
}


void Game::stopPause()
{
	state = previousState;
	pauseStartTime = 0;
	notify();
}

bool Game::getIsComputerShipSunk() const
{
	return isComputerShipSunk;
}
