/*
 * HumanPlayer.h
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_IMPLEMENTATIONS_HUMANPLAYER_H_
#define SRC_IMPLEMENTATIONS_HUMANPLAYER_H_

#include "Player.h"
#include <cstdlib>
#include <stdexcept>

class HumanPlayer: public Player {
public:
	HumanPlayer();
	~HumanPlayer();

	void initialize(int fieldSize);
	std::vector<int> makeShot();
	game::shotState checkShot(std::vector<int> hit);
	bool checkLoss();
	void notifyOnShot(game::shotState shotState);
	std::vector<int> getLastShot();
	std::vector<std::vector<int> > getShips();
private:
	std::vector<std::vector<int> > field;
	std::vector<std::vector<int> > shots;

	std::vector<int> lastShot;

	void setShips();
	void setShip(int size);

	int const FIELD_SIZE;

	bool checkPlaceForShip(int x, int y, int size, bool isHorizontal);
};

#endif /* SRC_IMPLEMENTATIONS_HUMANPLAYER_H_ */
