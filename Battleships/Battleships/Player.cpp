#include "Player.h"

Player::Player(void)
{
	isDefeat = false;
	lastHitX = 0;
	lastHitY = 0;
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

	fleet[0] = setShip(4);
	fleet[1] = setShip(3);
	fleet[2] = setShip(3);
	fleet[3] = setShip(2);
	fleet[4] = setShip(2);
	fleet[5] = setShip(2);
	fleet[6] = setShip(1);
	fleet[7] = setShip(1);
	fleet[8] = setShip(1);
	fleet[9] = setShip(1);
}

Ship Player::setShip(int size)
{
	int x;
	int y;
	int horizontal;
	Ship ship;

	if (size == 4)
	{
		srand(time(0));
		x = rand() % 10;
		y = rand() % 10;
		horizontal = rand() % 2;

		ships[x][y] = 1;

		if (horizontal == 0)	//корабль горизонтальный
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
		{	//корабль вертикальный
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

		return Ship(x, y, size, horizontal);
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

			place = checkPlace(x, y, horizontal, 3);
		}

		if (horizontal == 0) 
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
		return Ship(x, y, size, horizontal);
	}

	if (size == 2)
	{
		bool place = false;

		while (place == false) 
		{
			x = rand() % 10;
			y = rand() % 10;
			horizontal = rand() % 2;

			place = checkPlace(x, y, horizontal, 2);
		}

		if (horizontal == 0) 
		{
			ships[x][y] = 1;
			ships[x][y + 1] = 1;
		}
		else 
		{
			ships[x][y] = 1;
			ships[x + 1][y] = 1;
		}
		return Ship(x, y, size, horizontal);
	}

	if (size == 1)
	{
		bool place = false;

		while (place == false) 
		{
			x = rand() % 10;
			y = rand() % 10;

			place = checkPlace(x, y, 0, 1);
		}

		ships[x][y] = 1;
		return Ship(x, y, size, 0);
	}

	return ship;
}


bool Player::checkPlace(int x, int y, int horizontal, int size) {
	int a, b;
	if (ships[x][y] == 1)
		return false;

	if (horizontal == 0) {
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
	lastHitX = hit[0];
	lastHitY = hit[1];

	hits[hit[0]][hit[1]] = 1;
}

int Player::getLastHitX(void)
{
	return lastHitX;
}

int Player::getLastHitY(void)
{
	return lastHitY;
}

bool Player::isAnyShipHit(int x, int y)
{
	for (int i = 0; i < 10; i++) 
	{
		if (fleet[i].isShipCoordinates(x, y))
			return true;
	}

	return false;
}

bool Player::markSunkShips(int enemyHits[10][10])
{
	bool shipSunk = false;
	for (int i = 0; i < 10; i++)
	{
		if (fleet[i].getIsSunk() == false) 
		{
			cout << "  \b\b";
			shipSunk = fleet[i].isSunkCheck(enemyHits);
			if (shipSunk) 
			{
				fleet[i].setIsSunk(true);
				return true;
			}
		}
	}

	return false;
}

bool Player::getIsDeafeat(void)
{
	return isDefeat;
}

bool Player::checkEndOfGame()
{
	for (int i = 0; i<10; i++)
	{
		if (fleet[i].getIsSunk() == false)
			return false;
	}

	isDefeat = true;
	return true;
}

int Player::countSunkShips()
{
	int count = 0;
	for (int i = 0; i<10; i++) 
	{
		if (fleet[i].getIsSunk())
			count++;
	}

	return count;
}