#include "Player.h"

Player::Player()
{
	isDefeat = false;
}



Player::~Player()
{
}



void Player::initialize()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			ships[i][j] = 0;
			hits[i][j] = 0;
		}
	}

	fleet.push_front(setShip(4));
	fleet.push_front(setShip(3));
	fleet.push_front(setShip(3));
	fleet.push_front(setShip(2));
	fleet.push_front(setShip(2));
	fleet.push_front(setShip(2));
	fleet.push_front(setShip(1));
	fleet.push_front(setShip(1));
	fleet.push_front(setShip(1));
	fleet.push_front(setShip(1));
}



Ship Player::setShip(int size)
{
	int x = 0, y = 0;
	bool isHorizontal = false;

	bool place = false;

	while (place == false)
	{
		int x = rand() % 10;
		int y = rand() % 10;
	
		int horizontal = rand() % 2;

		if (horizontal == 0)
			isHorizontal = true;

		place = checkPlace(x, y, isHorizontal, size);
	}

	if (isHorizontal)
	{
		for (int i = y; i < y + size; i++) 
		{
			ships[x][i] = 1;
		}
	}
	else
	{
		for (int i = x; i < x + size; i++)
		{
			ships[i][y] = 1;
		}
	}

	return Ship(x, y, size, isHorizontal);
}



bool Player::checkPlace(int x, int y, bool isHorizontal, int size) {

	if (ships[x][y] == 1)
		return false;

	if (isHorizontal) {
		//check if the ship fits
		if (y>10 - size)
			return false;
		for (int i = y + 1; i<y + size; i++) 
		{
			if (ships[x][i] == 1)
				return false;
		}

		//check if cells around the ship are empty
		for (int i = x - 1; i<x + 2; i++)
		{
			if (i>-1 && i<10)
			{
				for (int j = y - 1; j<y + size + 1; j++) 
				{
					if (j>-1 && j<10) 
					{
						if (ships[i][j] == 1)
							return false;
					}
				}
			}
		}
	}
	else 
	{
		if (x>10 - size)
			return false;

		//check if the ship fits
		for (int i = x + 1; i<x + size; i++) 
		{
			if (ships[i][y] == 1)
				return false;
		}

		//check if cells around the ship are empty
		for (int i = x - 1; i<x + size + 1; i++) 
		{
			if (i>-1 && i<10)
			{
				for (int j = y - 1; j<y + 2; j++) 
				{
					if (j>-1 && j<10) 
					{
						if (ships[i][j] == 1)
							return false;
					}
				}
			}
		}
	}

	return true;
}



void Player::hit(int hit[2])
{
	hits[hit[0]][hit[1]] = 1;
}



bool Player::isAnyShipHit(int x, int y) 
{

	for (Ship &ship : fleet) {
		if(ship.isShipCoordinates(x, y))
			return true;
	}

	return false;
}



bool Player::markSunkShips(int enemyHits[10][10])
{
	bool shipSunk = false;

	for (Ship &ship : fleet) {
		if (ship.getIsSunk() == false)
		{
			cout << "  \b\b";
			shipSunk = ship.isSunkCheck(enemyHits);
			if (shipSunk)
			{
				ship.setIsSunk(true);
				return true;
			}
		}
	}

	return false;
}



bool Player::checkEndOfGame()
{

	for (Ship &ship : fleet) {
		if (ship.getIsSunk() == false)
			return false;
	}

	isDefeat = true;
	return true;
}



int Player::countSunkShips()
{
	int count = 0;

	for (Ship &ship : fleet) {
		if (ship.getIsSunk())
			count++;
	}

	return count;
}