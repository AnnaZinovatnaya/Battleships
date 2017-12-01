/*
 * Battleships.cpp
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#include "BattleshipsGame.h"
#include "Game.h"
#include "UI.h"

int main()
{
	game::Game * game;
	UI ui(game);

	game = new BattleshipsGame();
	game->start();
	delete game;

	return 0;
}


