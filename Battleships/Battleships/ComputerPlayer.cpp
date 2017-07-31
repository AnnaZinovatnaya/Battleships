#include "ComputerPlayer.h"



ComputerPlayer::ComputerPlayer()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cleverHits[i][j] = '1';
		}
	}
}


ComputerPlayer::~ComputerPlayer()
{
}


void ComputerPlayer::hit()
{
	bool suitableHit = false;
	int x = 0, y = 0;

	srand(time(0));

	while (suitableHit == false) {

		x = rand() % 10;
		y = rand() % 10;

		if (cleverHits[x][y] != '0' && cleverHits[x][y] != 'X') {
			suitableHit = true;
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
	
	//if (lastHitX > 0) 
			//if (lastHitX < 9) 
			//	if (lastHitY > 0) 
			//		if (lastHitX < 9) 			
	
}