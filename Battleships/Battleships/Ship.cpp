#include "Ship.h"

Ship::Ship()
{
	Ship::x = 0;
	Ship::y = 0;
	Ship::size = 0;
	Ship::isHorizontal = false;
	Ship::isSunk = false;
}



Ship::Ship(int x, int y, int size, bool isHorizontal)
{
	Ship::x = x;
	Ship::y = y;
	Ship::size = size;
	Ship::isHorizontal = isHorizontal;
	Ship::isSunk = false;
}



Ship::~Ship(void)
{
	Ship::x = 0;
	Ship::y = 0;
	Ship::size = 0;
	Ship::isHorizontal = false;
	Ship::isSunk = false;
}



bool Ship::isSunkCheck(int enemyHits[10][10])
{
	if (isHorizontal)
	{
		for (int i = y; i<y + size; i++)
		{
			if (enemyHits[x][i] != 1) 
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = x; i<x + size; i++)
		{
			if (enemyHits[i][y] != 1) 
			{
				return false;
			}
		}
	}

	return true;
}



bool Ship::isShipCoordinates(int hitX, int hitY)
{
	if (isHorizontal)
	{
		for (int i = y; i<y + size; i++)
		{
			if (x == hitX && i == hitY) 
			{
				return true;
			}
		}
	}
	else
	{
		for (int i = x; i<x + size; i++)
		{
			if (i == hitX && y == hitY) 
			{
				return true;
			}
		}
	}

	return false;
}