#ifndef ComputerPlayer_h__
#define ComputerPlayer_h__


#include "Player.h"

enum direction {TOP, RIGHT, BOTTOM, LEFT};

class ComputerPlayer: public Player
{
public:
	ComputerPlayer();
	~ComputerPlayer();

	void hit();

	int getLastHitX() { return lastHitX; }
	int getLastHitY() { return lastHitY; }

	void markMissedHit();
	void markSuccessHit();
	void markSunkShip();

private:
	char cleverHits[FIELD_SIZE][FIELD_SIZE]; //array that stores all hits and cells around sunk ships
	int lastHitX, lastHitY;

	direction chooseSideToHit() const;

	bool isShipHorizontal() const;
	int findShipFirstX(bool isHorizontal) const;
	int findShipFirstY(bool isHorizontal) const;
	int findShipSize(int firstX, int firstY, bool isHorizontal) const;

	void markShipAround(Ship &sunkShip);
};

#endif