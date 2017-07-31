#pragma once
#include "Player.h"

class ComputerPlayer: public Player
{
private:
	char cleverHits[10][10];
public:
	ComputerPlayer(void);
	~ComputerPlayer(void);

	void hit();
	
	void markMissedHit(void);
	void markSuccessHit(void);
	void markSunkShip(void);

	bool isShipHorizontal(void);
	int getShipFirstX(bool horizontal);
	int getShipFirstY(bool horizontal);
	int getShipSize(int firstX, int firstY, bool horizontal);

	void markShipAround(int firstX, int firstY, int size, bool horizontal);

};