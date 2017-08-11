#ifndef Player_h__
#define Player_h__


#include <cstdlib>
#include <ctime>
#include<iostream>
#include <list>

#include "Ship.h"

using namespace std;

class Player
{
public:
	int ships[FIELD_SIZE][FIELD_SIZE];
	int hits[FIELD_SIZE][FIELD_SIZE];
	list<Ship> fleet;

	Player();
	~Player();

	void initialize();

	void hit(int hit[2]);

	bool isAnyShipHit(int x, int y);
	bool markSunkShips(int enemyHits[FIELD_SIZE][FIELD_SIZE]);

	bool getIsDeafeat() { return isDefeat; }

	bool checkEndOfGame();
	int  countSunkShips();

private:
	bool isDefeat;

	Ship setShip(int size);
	bool checkPlace(int x, int y, bool isHorizontal, int size);
};

#endif