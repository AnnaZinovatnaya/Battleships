#pragma once

class Ship
{
public:
	Ship(void);
	Ship(int x, int y, int size, bool  isHorizontal);
	~Ship(void);

	bool isSunkCheck(int enemyHits[10][10]);
	bool isShipCoordinates(int hitX, int hitY);

	bool getIsSunk(void) { return isSunk; }
	void setIsSunk(bool newStatus) { isSunk = newStatus; }

private:
	int x;
	int y;
	int size;
	bool isHorizontal;
	bool isSunk;
};