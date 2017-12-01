/*
 * UI.h
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#ifndef SRC_IMPLEMENTATIONS_UI_H_
#define SRC_IMPLEMENTATIONS_UI_H_

#include "Observer.h"
#include "Game.h"
#include <vector>

class UI: public Observer {
public:
	UI(game::Game* game);
	~UI();

	void update();
private:
	game::Game* game;
	std::vector<std::vector<char> > map;

	static const int  VERTICAL_SIZE = 13, HORIZONTAL_SIZE = 49;
	const int FIELD_SIZE = 10;
};

#endif /* SRC_IMPLEMENTATIONS_UI_H_ */
