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
	this->x = x;
	this->y = y;
	this->size = size;
	this->isHorizontal = isHorizontal;
	this->isSunk = false;
}



Ship::~Ship()
{
	
}



bool Ship::isSunkCheck(int enemyHits[10][10]) const
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



bool Ship::isShipCoordinates(int hitX, int hitY) const
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