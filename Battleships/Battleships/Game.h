#ifndef Game_h__
#define Game_h__


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
	Game();
	~Game();

	void playGame();

private:
	Map map;
	Player human;
	ComputerPlayer computer;
	int timeOfGame;

	static const int MSG_VERTICAL_SIZE = 5, MSG_HORIZONTALAL_SIZE = 25;
	static const int COLUMN_POSITION_FOR_USER_HIT = 0;
	static const int ROW_POSITION_FOR_USER_HIT = 18;

	void convertHumanHitToInt(char cHit[3], int humanHit[2]) const;
	bool checkHumanHit(char hit[3]) const;

	bool checkEndOfGame();
	void showStatistics();
	void showEndMessage(char message[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE]);

	bool listenKeyPress(short p_key) const;

	void pause() const;

	void setCursorPosition(int column, int row) const;

	void waitForEnterPressed() const;
};

#endif