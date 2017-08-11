#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer()
{
	for (int i = 0; i < FIELD_SIZE; i++) 
	{
		for (int j = 0; j < FIELD_SIZE; j++) 
		{
			cleverHits[i][j] = '1';
		}
	}

	lastHitX = 0;
	lastHitY = 0;
}



ComputerPlayer::~ComputerPlayer()
{
}



void ComputerPlayer::hit()
{
	bool lastHitSuccessful = false;
	int x = 0, y = 0;
	
	if (cleverHits[lastHitX][lastHitY] == 'X')
		lastHitSuccessful = true;

	//if computer hit any human's ship, it hits around that cell (not randomly)
	if (lastHitSuccessful)
	{

		direction direction = chooseSideToHit();

		if (direction == TOP) 
		{ 
			x = lastHitX - 1; 
			y = lastHitY; 
		} 
		else if (direction == BOTTOM)
		{
			x = lastHitX + 1;
			y = lastHitY;
			
		}
		else if (direction == LEFT)
		{
			x = lastHitX;
			y = lastHitY - 1;
		}
		else if (direction == RIGHT)
		{
			x = lastHitX;
			y = lastHitY + 1;
		}

	}
	else 
	{
		bool suitableHit = false;

		while (suitableHit == false) 
		{
			x = rand() % FIELD_SIZE;
			y = rand() % FIELD_SIZE;

			if (cleverHits[x][y] != '0' && cleverHits[x][y] != 'X') 
			{
				suitableHit = true;
			}
		}
	}

	hits[x][y] = 1;

	lastHitX = x;
	lastHitY = y;
}



void ComputerPlayer::markMissedHit() 
{
	cleverHits[lastHitX][lastHitY] = '0';
}



void ComputerPlayer::markSuccessHit()
{
	cleverHits[lastHitX][lastHitY] = 'X';
}



void ComputerPlayer::markSunkShip()
{
	bool isHorizontal = isShipHorizontal();

	int firstX = findShipFirstX(isHorizontal);
	int firstY = findShipFirstY(isHorizontal);

	int size = findShipSize(firstX, firstY, isHorizontal);

	Ship foundShip(firstX, firstY, size, isHorizontal);

	markShipAround(foundShip);
}



bool ComputerPlayer::isShipHorizontal() const
{

	if (lastHitY == 0) 
	{
		if (cleverHits[lastHitX][lastHitY + 1] == 'X')
			return true;
	}
	else if (lastHitY > 0 && lastHitY < FIELD_SIZE - 1) 
	{
		if (cleverHits[lastHitX][lastHitY - 1] == 'X' || 
				cleverHits[lastHitX][lastHitY + 1] == 'X')
			return true;
	}
	else if (lastHitY == FIELD_SIZE - 1) 
	{
		if (cleverHits[lastHitX][lastHitY - 1] == 'X')
			return true;
	}

	return false;
}



int ComputerPlayer::findShipFirstX(bool isHorizontal) const
{
	if (isHorizontal)
	{
		return lastHitX;
	}
	else 
	{
		if (lastHitX == 0) 
		{
			return lastHitX;
		}
		else 
		{
			int currentX = lastHitX;

			while (currentX >= 0) 
			{
				if (cleverHits[currentX][lastHitY] == 'X') 
				{
					currentX--;
				}
				else 
				{
					return currentX + 1;
				}
			}

			return currentX+1;			
		}
	}

	return 0;
}



int ComputerPlayer::findShipFirstY(bool isHorizontal) const
{
	if (isHorizontal)
	{
		if (lastHitX == 0) 
		{
			return lastHitX;
		}
		else 
		{
			int currentY = lastHitY;

			while (currentY >= 0) 
			{
				if (cleverHits[lastHitX][currentY] == 'X') 
				{
					currentY--;
				}
				else 
				{
					return currentY + 1;
				}
			}

			return currentY + 1;
		}
	}
	else 
	{
		return lastHitY;
	}

	return 0;
}



int ComputerPlayer::findShipSize(int firstX, int firstY, bool isHorizontal) const
{
	int size = 1;

	if (isHorizontal)
	{
		int currentY = firstY + 1;
		while (currentY <= FIELD_SIZE - 1) 
		{
			if (cleverHits[firstX][currentY] == 'X') 
			{
				currentY++;
				size++;
			}
			else 
			{
				break;
			}
		}

		return size;

	}
	else 
	{
		int currentX = firstX+1;
		while (currentX <= FIELD_SIZE - 1) 
		{
			if (cleverHits[currentX][firstY] == 'X') 
			{
				currentX++;
				size++;
			}
			else 
			{
				break;
			}
		}

		return size;
	}

	return 0;
}

void ComputerPlayer::markShipAround(Ship & sunkShip)
{
	if (sunkShip.getIsHorizontal())
	{
		for (int i = sunkShip.getX() - 1; i<sunkShip.getX() + 2; i++)
		{
			if (i > -1 && i < FIELD_SIZE)
			{
				for (int j = sunkShip.getY() - 1; j < sunkShip.getY() + sunkShip.getSize() + 1; j++)
				{
					if (j > -1 && j < FIELD_SIZE)
					{
						if (cleverHits[i][j] == '1')
							cleverHits[i][j] = '0';
					}
				}
			}
		}
	}
	else
	{
		for (int i = sunkShip.getX() - 1; i < sunkShip.getX() + sunkShip.getSize() + 1; i++)
		{
			if (i > -1 && i < FIELD_SIZE)
			{
				for (int j = sunkShip.getY() - 1; j < sunkShip.getY() + 2; j++)
				{
					if (j > -1 && j < FIELD_SIZE)
					{
						if (cleverHits[i][j] == '1')
							cleverHits[i][j] = '0';
					}
				}
			}
		}
	}
}



direction ComputerPlayer::chooseSideToHit() const
{
	if (lastHitX > 0 && cleverHits[lastHitX - 1][lastHitY] == '1')
	{
		return TOP;
	}

	if (lastHitX < FIELD_SIZE - 1 && cleverHits[lastHitX + 1][lastHitY] == '1')
	{
		return BOTTOM;
	}

	if (lastHitY > 0 && cleverHits[lastHitX][lastHitY - 1] == '1')
	{
		return LEFT;
	}

	if (lastHitY < FIELD_SIZE - 1 && cleverHits[lastHitX][lastHitY + 1] == '1')
	{
		return RIGHT;
	}
}
