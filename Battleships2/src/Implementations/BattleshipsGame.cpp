/*
 * BattleshipsGame.cpp
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#include "BattleshipsGame.h"

BattleshipsGame::BattleshipsGame() {
	player1 = new HumanPlayer();
	player2 = new HumanPlayer();
	//player2 = new ComputerPlayer();

	player1 -> initialize(FIELD_SIZE);
	player2 -> initialize(FIELD_SIZE);

	notify();
}

BattleshipsGame::~BattleshipsGame() {
}

void BattleshipsGame::start() {
	bool endOfGame = false;

	while(!endOfGame) {
		std::vector<int> shot = player1 -> makeShot();
		game::shotState shotState = player2 -> checkShot(shot);
		player1 -> notifyOnShot(shotState);
		endOfGame = player2 -> checkLoss();
		notify();

		if(!endOfGame) {
			std::vector<int> shot = player2 -> makeShot();
			game::shotState shotState = player1 -> checkShot(shot);
			player2 -> notifyOnShot(shotState);
			endOfGame = player1 -> checkLoss();
			notify();
		}
	}
}

void BattleshipsGame::attach(Observer* observer)
{
  observers.push_back(observer);
}



void BattleshipsGame::detach(Observer* observer)
{
  observers.remove(observer);
}



void BattleshipsGame::notify()
{
  for (Observer* observer : observers) {
    observer->update();
  }
}

std::vector<std::vector<int> > BattleshipsGame::getPlayer1Ships() {
	return player1 -> getShips();
}
