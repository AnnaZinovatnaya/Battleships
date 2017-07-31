#pragma once
#include <cstdlib>;
#include <ctime>;
#include "Ship.h";


#include<iostream>
using namespace std;
class Player
{
private:
	//int ships[10][10];
	bool isDefeat;
	//Ship fleet[10];
protected:
	int lastHitX, lastHitY;
	//int hits[10][10];
public:
	int ships[10][10];
	int hits[10][10];
	Ship fleet[10];

	Player(void);
	~Player(void);

	void initialize(void);
	Ship setShip(int size);
	bool checkPlace(int x, int y, int horizontal, int size);
	void hit(int hit[2]);

	int getLastHitX(void);
	int getLastHitY(void);

	bool isAnyShipHit(int x, int y);
	bool markSunkShips(int enemyHits[10][10]);

	bool getIsDeafeat(void);
	bool checkEndOfGame();
	int countSunkShips();
};