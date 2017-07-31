#pragma once
class Ship
{
private:
	int x;
	int y;
	int size;
	bool isHorizontal;
	bool isSunk;
public:
	Ship(void);
	Ship(int x, int y, int size, bool  isHorizontal);
	~Ship(void);
	bool isSunkCheck(int enemyHits[10][10]);
	bool isShipCoordinates(int hitX, int hitY);
	bool getIsSunk(void);
	void setIsSunk(bool newStatus);
};