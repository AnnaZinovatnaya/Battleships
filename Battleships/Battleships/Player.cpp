#include "Player.h"

Player::Player(void)
{
	isDefeat = false;
}



Player::~Player(void)
{
}



void Player::initialize(void)
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
	int x  = 0;
	int y = 0;
	bool isHorizontal = false;
	int horizontal = 0;
	Ship ship;

	if (size == 4)
	{
		srand(time(0));
		x = rand() % 10;
		y = rand() % 10;
		horizontal = rand() % 2;
		if (horizontal == 0)
			isHorizontal = true;

		ships[x][y] = 1;

		if (isHorizontal)
		{
			if (y<7)
			{
				ships[x][y + 1] = 1;
				ships[x][y + 2] = 1;
				ships[x][y + 3] = 1;
			}
			else 
			{
				ships[x][y - 1] = 1;
				ships[x][y - 2] = 1;
				ships[x][y - 3] = 1;
			}
		}
		else 
		{	
			if (x<7)
			{
				ships[x + 1][y] = 1;
				ships[x + 2][y] = 1;
				ships[x + 3][y] = 1;
			}
			else 
			{
				ships[x - 1][y] = 1;
				ships[x - 2][y] = 1;
				ships[x - 3][y] = 1;
			}
		}

		return Ship(x, y, size, isHorizontal);
	}

	if (size == 3)
	{
		bool place = false;

		while (place == false) 
		{
			srand(time(0));
			x = rand() % 10;
			y = rand() % 10;
			horizontal = rand() % 2;
			if (horizontal == 0)
				isHorizontal = true;

			place = checkPlace(x, y, isHorizontal, 3);
		}

		if (isHorizontal) 
		{
			ships[x][y] = 1;
			ships[x][y + 1] = 1;
			ships[x][y + 2] = 1;
		}
		else 
		{
			ships[x][y] = 1;
			ships[x + 1][y] = 1;
			ships[x + 2][y] = 1;
		}
		return Ship(x, y, size, isHorizontal);
	}

	if (size == 2)
	{
		bool place = false;

		while (place == false) 
		{
			x = rand() % 10;
			y = rand() % 10;
			horizontal = rand() % 2;
			if (horizontal == 0)
				isHorizontal = true;

			place = checkPlace(x, y, isHorizontal, 2);
		}

		if (isHorizontal) 
		{
			ships[x][y] = 1;
			ships[x][y + 1] = 1;
		}
		else 
		{
			ships[x][y] = 1;
			ships[x + 1][y] = 1;
		}
		return Ship(x, y, size, isHorizontal);
	}

	if (size == 1)
	{
		bool place = false;

		while (place == false) 
		{
			x = rand() % 10;
			y = rand() % 10;

			place = checkPlace(x, y, false, 1);
		}

		ships[x][y] = 1;
		return Ship(x, y, size, false);
	}

	return ship;
}



bool Player::checkPlace(int x, int y, bool isHorizontal, int size) {

	if (ships[x][y] == 1)
		return false;

	if (isHorizontal) {
		//проверка, станет ли корабль
		if (y>10 - size)
			return false;
		for (int i = y + 1; i<y + size; i++) 
		{
			if (ships[x][i] == 1)
				return false;
		}

		//проверка, свободно ли вокруг него
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

		//проверка, станет ли корабль
		for (int i = x + 1; i<x + size; i++) 
		{
			if (ships[i][y] == 1)
				return false;
		}

		//проверка, свободно ли вокруг него
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