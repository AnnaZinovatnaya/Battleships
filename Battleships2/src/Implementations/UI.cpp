/*
 * UI.cpp
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#include "UI.h"

UI::UI(game::Game* game) {

	this->game = game;

	char tempMap[VERTICAL_SIZE][HORIZONTAL_SIZE] = {
			"   0123456789     0123456789 ",
			"  #----------#   #----------#",
			" A|          |  A|          |",
			" B|          |  B|          |",
			" C|          |  C|          |",
			" D|          |  D|          |",
			" E|          |  E|          |",
			" F|          |  F|          |",
			" G|          |  G|          |",
			" H|          |  H|          |",
			" I|          |  I|          |",
			" J|          |  J|          |",
			"  #----------#   #----------#"
		};

		std::vector<char> row(HORIZONTAL_SIZE, '0');
		std::vector<std::vector<char> > map(VERTICAL_SIZE, row);

		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++)
				map[i][j] = tempMap[i][j];
		}

		this->game = game;
		game->attach(this);

		std::vector<std::vector<int> > userShips = game->getPlayer1Ships();

		for (int i = 0; i < FIELD_SIZE; i++) {
			for (int j = 0; j < FIELD_SIZE; j++) {
				if (userShips[i][j] == 1)
					map[i + 2][j + 3] = 'S';
			}
		}

		this->map = map;
}

UI::~UI() {
	// TODO Auto-generated destructor stub
}

void UI::update() {

}

