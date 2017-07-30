#pragma once

#include "Map.h"
#include "Player.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <windows.h>


using namespace std;

class Game
{
	Map map;
	Player human;
	Player computer;
	static const int MSG_VERTICAL_SIZE = 5, MSG_HORIZONTALAL_SIZE = 25;
	int timeOfGame;

public:
	Game(void);
	~Game(void);

	void initializeGame(void);
	void playGame(void);
	bool checkHit(char hit[3]);
	bool checkEndOfGame(void);
	void showStatistics(void);
	void showMessage(char message[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE]);
	void generateComputerHit(int computerHits[10][10], int hitStorage[2]);
	void convertHumanHit(char cHit[3], int humanHit[2]);
	bool listenKeyPress(short p_key);
	void pauseGame(void);

};

