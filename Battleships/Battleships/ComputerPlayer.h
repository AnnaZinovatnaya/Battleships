#pragma once
#include "Player.h"

class ComputerPlayer: public Player
{
private:
	char cleverHits[10][10];
	int lastHitX, lastHitY;
public:
	ComputerPlayer(void);
	~ComputerPlayer(void);

	void hit();

	int getLastHitX(void);
	int getLastHitY(void);
	
	void markMissedHit(void);
	void markSuccessHit(void);
	void markSunkShip(void);

	bool isShipHorizontal(void);
	int getShipFirstX(bool isHorizontal);
	int getShipFirstY(bool isHorizontal);
	int getShipSize(int firstX, int firstY, bool isHorizontal);

	void markShipAround(int firstX, int firstY, int size, bool isHorizontal);
};