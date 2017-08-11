#pragma once

class Ship
{
public:
	Ship();
	Ship(int x, int y, int size, bool  isHorizontal);
	~Ship();

	bool isSunkCheck(int enemyHits[10][10]) const;
	bool isShipCoordinates(int hitX, int hitY) const;

	bool getIsSunk() const  { return isSunk; }
	void setIsSunk(bool newStatus) { isSunk = newStatus; }

	int getX() const { return x; }
	
	int getY() const { return y; }

	bool getIsHorizontal() const { return isHorizontal; }

	int getSize() const { return size; }


private:
	int x;
	int y;
	int size;
	bool isHorizontal;
	bool isSunk;
};