/*
 * Player.h
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_INTERFACES_PLAYER_H_
#define SRC_INTERFACES_PLAYER_H_

#include "Game.h"
#include <vector>

class Player {
public:
	Player();
	virtual ~Player();

	virtual void initialize(int fieldSize) = 0;
	virtual std::vector<int> makeShot() = 0;
	virtual game::shotState checkShot(std::vector<int> hit) = 0;
	virtual bool checkLoss() = 0;
	virtual void notifyOnShot(game::shotState shotState) = 0;
	virtual std::vector<int> getLastShot() = 0;

	virtual std::vector<std::vector<int> > getShips() = 0;
};

#endif /* SRC_INTERFACES_PLAYER_H_ */
