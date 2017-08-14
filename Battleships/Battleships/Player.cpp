#include "Player.h"


Player::Player()
{
	vector<int> row(FIELD_SIZE, 0);
	vector<vector<int> > ships(FIELD_SIZE, row);
	vector<vector<int> > hits(FIELD_SIZE, row);

	this->ships = ships;
	this->hits = hits;

	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			this->ships[i][j] = 0;
			this->hits[i][j] = 0;
		}
	}
}



Player::~Player()
{
}



void Player::initialize()
{
	fleet.push_back(setShip(4));
	fleet.push_back(setShip(3));
	fleet.push_back(setShip(3));
	fleet.push_back(setShip(2));
	fleet.push_back(setShip(2));
	fleet.push_back(setShip(2));
	fleet.push_back(setShip(1));
	fleet.push_back(setShip(1));
	fleet.push_back(setShip(1));
	fleet.push_back(setShip(1));
}



vector<vector<int>> Player::getShips() const
{
	return ships;
}



vector<vector<int>> Player::getHits() const
{
	return hits;
}



list<Ship> Player::getFleet() const
{
	return fleet;
}



Ship Player::setShip(int size)
{
	int x = 0, y = 0;
	bool isHorizontal = false;
	bool place = false;

	while (place == false)
	{
		x = rand() % FIELD_SIZE;
		y = rand() % FIELD_SIZE;
	
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
		if (y > FIELD_SIZE - size)
			return false;
		for (int i = y + 1; i < y + size; i++) 
		{
			if (ships[x][i] == 1)
				return false;
		}

		//check if cells around the ship are empty
		for (int i = x - 1; i < x + 2; i++)
		{
			if (i > -1 && i < FIELD_SIZE)
			{
				for (int j = y - 1; j < y + size + 1; j++) 
				{
					if (j > -1 && j < FIELD_SIZE) 
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
		if (x > FIELD_SIZE - size)
			return false;

		//check if the ship fits
		for (int i = x + 1; i < x + size; i++) 
		{
			if (ships[i][y] == 1)
				return false;
		}

		//check if cells around the ship are empty
		for (int i = x - 1; i < x + size + 1; i++) 
		{
			if (i > -1 && i < FIELD_SIZE)
			{
				for (int j = y - 1; j < y + 2; j++) 
				{
					if (j > -1 && j < FIELD_SIZE) 
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



void Player::hit(vector<int> hit)
{
	hits[hit[0]][hit[1]] = 1;
}



bool Player::isAnyShipHit(int x, int y) const
{

	for (Ship const &ship : fleet) {
		if(ship.isShipCoordinates(x, y))
			return true;
	}

	return false;
}



bool Player::markSunkShips(vector<vector<int> > enemyHits)
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



bool Player::checkDefeat() const
{

	for (Ship const & ship : fleet) {
		if (ship.getIsSunk() == false)
			return false;
	}

	return true;
}



int Player::countSunkShips() const
{
	int count = 0;

	for (Ship const &ship : fleet) {
		if (ship.getIsSunk())
			count++;
	}

	return count;
}