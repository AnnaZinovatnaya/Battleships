#include "Ship.h"

Ship::Ship()
{
	x = 0;
	y = 0;
	size = 0;
	isHorizontal = false;
	isSunk = false;
}



Ship::Ship(int x, int y, int size, bool isHorizontal)
{
	x = x;
	y = y;
	size = size;
	isHorizontal = isHorizontal;
	isSunk = false;
}



Ship::~Ship()
{
	x = 0;
	y = 0;
	size = 0;
	isHorizontal = false;
	isSunk = false;
}



bool Ship::isSunkCheck(int enemyHits[FIELD_SIZE][FIELD_SIZE]) const
{
	if (isHorizontal)
	{
		for (int i = y; i < y + size; i++)
		{
			if (enemyHits[x][i] != 1) 
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = x; i < x + size; i++)
		{
			if (enemyHits[i][y] != 1) 
			{
				return false;
			}
		}
	}

	return true;
}



bool Ship::isShipCoordinates(int hitX, int hitY) const
{
	if (isHorizontal)
	{
		for (int i = y; i < y + size; i++)
		{
			if (x == hitX && i == hitY) 
			{
				return true;
			}
		}
	}
	else
	{
		for (int i = x; i < x + size; i++)
		{
			if (i == hitX && y == hitY) 
			{
				return true;
			}
		}
	}

	return false;
}