/*
 * BattleshipsGame.h
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_IMPLEMENTATIONS_BATTLESHIPSGAME_H_
#define SRC_IMPLEMENTATIONS_BATTLESHIPSGAME_H_

#include "Game.h"
#include "Observer.h"
#include "Player.h"
#include "HumanPlayer.h"
#include <list>

class BattleshipsGame: public game::Game {
public:
	BattleshipsGame();
	~BattleshipsGame();

	void start();

    void attach(Observer* observer);
    void detach(Observer* observer);

    std::vector<std::vector<int> > getPlayer1Ships();
private:
	Player * player1;
	Player * player2;

	std::list<Observer*> observers;

	int const FIELD_SIZE = 10;

    void notify();


};

#endif /* SRC_IMPLEMENTATIONS_BATTLESHIPSGAME_H_ */
