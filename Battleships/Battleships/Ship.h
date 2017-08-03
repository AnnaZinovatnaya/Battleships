#pragma once

class Ship
{
public:
	Ship(void);
	Ship(int x, int y, int size, bool  isHorizontal);
	~Ship(void);

	bool isSunkCheck(int enemyHits[10][10]) const;
	bool isShipCoordinates(int hitX, int hitY) const;

	bool getIsSunk(void) const  { return isSunk; }
	void setIsSunk(bool newStatus) { isSunk = newStatus; }

	int getX(void) const { return x; }
	
	int getY(void) const { return y; }

	bool getIsHorizontal(void) const { return isHorizontal; }

	int getSize(void) const { return size; }


private:
	int x;
	int y;
	int size;
	bool isHorizontal;
	bool isSunk;
};