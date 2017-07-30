#include "Ship.h"

Ship::Ship()
{
	Ship::x = 0;
	Ship::y = 0;
	Ship::size = 0;
	Ship::horizontal = 0;
	Ship::isSunk = false;
}

Ship::Ship(int x, int y, int size, int horizontal)
{
	Ship::x = x;
	Ship::y = y;
	Ship::size = size;
	Ship::horizontal = horizontal;
	Ship::isSunk = false;
}


Ship::~Ship(void)
{
	Ship::x = 0;
	Ship::y = 0;
	Ship::size = 0;
	Ship::horizontal = 0;
	Ship::isSunk = false;
}

bool Ship::isSunkCheck(int enemyHits[10][10])
{
	if (horizontal == 0)
	{
		for (int i = y; i<y + size; i++)
		{
			if (enemyHits[x][i] != 1) {
				return false;
			}
		}
	}
	else
	{
		for (int i = x; i<x + size; i++)
		{
			if (enemyHits[i][y] != 1) {
				return false;
			}
		}
	}

	return true;
}

