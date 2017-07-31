#pragma once
class Ship
{
public:
	int x;
	int y;
	int size;
	int horizontal;
	bool isSunk;

	Ship(void);
	Ship(int x, int y, int size, int horizontal);
	~Ship(void);
	bool isSunkCheck(int enemyHits[10][10]);
	bool isShipCoordinates(int hitX, int hitY);
};

