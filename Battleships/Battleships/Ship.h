#pragma once
class Ship
{
private:
	int x;
	int y;
	int size;
	int horizontal;
	bool isSunk;
public:
	Ship(void);
	Ship(int x, int y, int size, int horizontal);
	~Ship(void);
	bool isSunkCheck(int enemyHits[10][10]);
	bool isShipCoordinates(int hitX, int hitY);
	bool getIsSunk(void);
	void setIsSunk(bool newStatus);
};s