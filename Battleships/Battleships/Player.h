#pragma once
#include <cstdlib>;
#include <ctime>;
#include "Ship.h";


#include<iostream>
using namespace std;
class Player
{
public:

	int ships[10][10];
	int hits[10][10];
	int lastHitX, lastHitY;
	bool defeatFlag;
	Ship fleet[10];

	Player(void);
	~Player(void);

	void initialize(void);
	Ship setShip(int size);
	bool checkPlace(int x, int y, int horizontal, int size);
	void hit(int hit[2]);
	bool checkEndOfGame();
	bool markSunkShips(int enemyHits[10][10]);
	int countSunkShips();
	bool isAnyShipHit(int x, int y);
};


