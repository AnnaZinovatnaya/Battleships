#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer()
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) 
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
	bool suitableHit = false;
	int x = 0, y = 0;
	
	//if computer hit any human's ship, it hits around that cell (not randomly)
	if (cleverHits[lastHitX][lastHitY] == 'X') 
	{
		if (lastHitX > 0 && cleverHits[lastHitX - 1][lastHitY] == '1') 
		{
			x = lastHitX - 1;
			y = lastHitY;
		}
		if (lastHitX < 9 && cleverHits[lastHitX + 1][lastHitY] == '1') 
		{
			x = lastHitX + 1;
			y = lastHitY;
		}
		if (lastHitY > 0 && cleverHits[lastHitX][lastHitY - 1] == '1') 
		{
			x = lastHitX;
			y = lastHitY - 1;
		}
		if (lastHitY < 9 && cleverHits[lastHitX ][lastHitY + 1] == '1') 
		{
			x = lastHitX;
			y = lastHitY + 1;
		}
	}
	else 
	{
		srand(time(0));

		while (suitableHit == false) 
		{
			x = rand() % 10;
			y = rand() % 10;

			if (cleverHits[x][y] != '0' && cleverHits[x][y] != 'X') 
			{
				suitableHit = true;
			}
		}
	}
	
	lastHitX = x;
	lastHitY = y;

	hits[x][y] = 1;
}



void ComputerPlayer::markMissedHit(void) 
{
	cleverHits[lastHitX][lastHitY] = '0';
}



void ComputerPlayer::markSuccessHit(void)
{
	cleverHits[lastHitX][lastHitY] = 'X';
}



void ComputerPlayer::markSunkShip(void)
{
	bool isHorizontal = false;
	int size = 0;
	int firstX = 0, firstY = 0;

	isHorizontal = isShipHorizontal();

	firstX = getShipFirstX(isHorizontal);
	firstY = getShipFirstY(isHorizontal);

	size = getShipSize(firstX, firstY, isHorizontal);

	ComputerPlayer::markShipAround(firstX, firstY, size, isHorizontal);
}



bool ComputerPlayer::isShipHorizontal(void)
{

	if (lastHitY == 0) 
	{
		if (cleverHits[lastHitX][lastHitY + 1] == 'X')
			return true;
	}
	else if (lastHitY > 0 && lastHitY < 9) 
	{
		if (cleverHits[lastHitX][lastHitY - 1] == 'X' || 
				cleverHits[lastHitX][lastHitY + 1] == 'X')
			return true;
	}
	else if (lastHitY == 9) 
	{
		if (cleverHits[lastHitX][lastHitY - 1] == 'X')
			return true;
	}

	return false;
}



int ComputerPlayer::getShipFirstX(bool isHorizontal)
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

			while (currentX>=0) 
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



int ComputerPlayer::getShipFirstY(bool isHorizontal)
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



int ComputerPlayer::getShipSize(int firstX, int firstY, bool isHorizontal)
{
	int size = 1;

	if (isHorizontal)
	{
		int currentY = firstY+1;
		while (currentY <= 9) 
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
		while (currentX <= 9) 
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



void ComputerPlayer::markShipAround(int firstX, int firstY, 
	int size, bool isHorizontal)
{
	if (isHorizontal)
	{
		for (int i = firstX - 1; i<firstX + 2; i++) 
		{
			if (i>-1 && i<10)
			{
				for (int j = firstY - 1; j<firstY + size + 1; j++) 
				{
					if (j>-1 && j<10) 
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
		for (int i = firstX - 1; i<firstX + size + 1; i++) 
		{
			if (i>-1 && i<10)
			{
				for (int j = firstY - 1; j<firstY + 2; j++) 
				{
					if (j>-1 && j<10) 
					{
						if (cleverHits[i][j] == '1')
							cleverHits[i][j] = '0';
					}
				}
			}
		}
	}
}