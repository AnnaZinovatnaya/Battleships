#pragma once
#include "Player.h"

enum direction {TOP, RIGHT, BOTTOM, LEFT};

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

	direction chooseSideToHit(void) const;

	bool isShipHorizontal(void) const;
	int findShipFirstX(bool isHorizontal) const;
	int findShipFirstY(bool isHorizontal) const;
	int findShipSize(int firstX, int firstY, bool isHorizontal) const;

	void markShipAround(Ship &sunkShip);
};