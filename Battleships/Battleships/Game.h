#pragma once

#include <conio.h>
#include <iostream>
#include <ctime>
#include <windows.h>

#include "ComputerPlayer.h"
#include "Map.h"
#include "Player.h"

using namespace std;

class Game
{
public:
	Game(void);
	~Game(void);

	void playGame(void);

private:
	Map map;
	Player human;
	ComputerPlayer computer;
	int timeOfGame;
	static const int MSG_VERTICAL_SIZE = 5, MSG_HORIZONTALAL_SIZE = 25;
	static const int COLUMN_POSITION_FOR_USER_HIT = 0;
	static const int ROW_POSITION_FOR_USER_HIT = 18;

	void convertHumanHitToInt(char cHit[3], int humanHit[2]);
	bool checkHit(char hit[3]);

	bool checkEndOfGame(void);
	void showStatistics(void);
	void showEndMessage(char message[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE]);

	bool listenKeyPress(short p_key);

	void pause(void);

	void setCursorPosition(int column, int row);
};