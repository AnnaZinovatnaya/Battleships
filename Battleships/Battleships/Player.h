#pragma once

#include <cstdlib>
#include <ctime>
#include<iostream>
#include <list>

#include "Ship.h"

using namespace std;

class Player
{
public:
	static const int NUMBER_OF_SHIPS = 10;
	int ships[10][10];
	int hits[10][10];
	list<Ship> fleet;

	Player(void);
	~Player(void);

	void initialize(void);

	void hit(int hit[2]);

	bool isAnyShipHit(int x, int y);
	bool markSunkShips(int enemyHits[10][10]);

	bool getIsDeafeat(void) { return isDefeat; }

	bool checkEndOfGame();
	int  countSunkShips();

private:
	bool isDefeat;

	Ship setShip(int size);
	bool checkPlace(int x, int y, bool isHorizontal, int size);
};