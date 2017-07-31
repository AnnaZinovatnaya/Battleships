#pragma once

#include "Map.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

class Game
{
private:
	Map map;
	Player human;
	ComputerPlayer computer;
	int timeOfGame;
	static const int MSG_VERTICAL_SIZE = 5, MSG_HORIZONTALAL_SIZE = 25;

public:
	Game(void);
	~Game(void);

	void playGame(void);

	void convertHumanHitToInt(char cHit[3], int humanHit[2]);
	bool checkHit(char hit[3]);

	bool checkEndOfGame(void);
	void showStatistics(void);
	void showEndMessage(char message[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE]);

	bool listenKeyPress(short p_key);

	void pause(void);

	void setCursorPosition(int column, int row);
};