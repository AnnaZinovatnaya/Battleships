#pragma once
#include "Player.h"

class ComputerPlayer: public Player
{
public:
	ComputerPlayer(void);
	~ComputerPlayer(void);

	void hit();

	int getLastHitX(void) { return lastHitX; }
	int getLastHitY(void) { return lastHitY; }

	void markMissedHit(void);
	void markSuccessHit(void);
	void markSunkShip(void);

private:
	char cleverHits[10][10]; //array that stores all hits and cells aroung sunk ships
	int lastHitX, lastHitY;

	bool isShipHorizontal(void) const;
	int getShipFirstX(bool isHorizontal) const;
	int getShipFirstY(bool isHorizontal) const;
	int getShipSize(int firstX, int firstY, bool isHorizontal) const;

	void markShipAround(Ship &sunkShip);
};