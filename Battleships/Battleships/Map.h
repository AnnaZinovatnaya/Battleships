#pragma once

#include <Windows.h>
#include "Player.h"

class Map
{
public:
	Map();
	~Map();

	void initialize(Player &human);

	void update(Player &human, Player &computer);

	void showEndMap(Player &human, Player &computer);

private:
	static const int  VERTICAL_SIZE = 13, HORIZONTAL_SIZE = 49;
	char map[VERTICAL_SIZE][HORIZONTAL_SIZE];
};