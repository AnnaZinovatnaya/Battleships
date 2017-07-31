#pragma once
#include "Player.h"

class ComputerPlayer: public Player
{
public:
	char cleverHits[10][10];
	bool nextHitRandom;// '0' if missed or shoud not hit there, 'X' if hit


	ComputerPlayer(void);
	~ComputerPlayer(void);

	void hit();
	
	void markMissedHit(void);
	void markSuccessHit(void);
	void markSunkShip(void);

	bool isShipHorizontal(void);
	int getShipSize(int firstX, int firstY, bool horizontal);
	int getShipFirstX(bool horizontal);
	int getShipFirstY(bool horizontal);

	void markShip(int firstX, int firstY, int size, bool horizontal);

};

