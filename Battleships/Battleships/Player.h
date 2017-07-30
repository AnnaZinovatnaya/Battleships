#pragma once
#include <cstdlib>;
#include <ctime>;
#include "Ship.h";

class Player
{
public:

	int ships[10][10];
	int hits[10][10];
	bool defeatFlag;
	Ship fleet[10];

	Player(void);
	~Player(void);

	void initialize(void);
	Ship setShip(int size);
	bool checkPlace(int x, int y, int horizontal, int size);
	void hit(int hit[2]);
	bool checkEndOfGame();
	void markSunkShips(int enemyHits[10][10]);
	int countSunkShips();
};


