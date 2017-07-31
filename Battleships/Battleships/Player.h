#pragma once
#include <cstdlib>
#include <ctime>
#include "Ship.h"
#include<iostream>

using namespace std;
class Player
{
private:
	bool isDefeat;
public:
	int ships[10][10];
	int hits[10][10];
	Ship fleet[10];

	Player(void);
	~Player(void);

	void initialize(void);
	Ship setShip(int size);
	bool checkPlace(int x, int y, bool isHorizontal, int size);
	void hit(int hit[2]);

	bool isAnyShipHit(int x, int y);
	bool markSunkShips(int enemyHits[10][10]); 

	bool getIsDeafeat(void);
	bool checkEndOfGame();
	int countSunkShips();
};