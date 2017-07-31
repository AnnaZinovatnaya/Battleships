#pragma once
#include "Player.h"

class ComputerPlayer: public Player
{
public:
	char cleverHits[10][10]; // '0' if missed or shoud not hit there, 'X' if hit


	ComputerPlayer(void);
	~ComputerPlayer(void);

	void hit();
	
	void markMissedHit(void);
	void markSuccessHit(void);
	void markSunkShip(void);
};

