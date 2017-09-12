#ifndef ConsoleView_h__
#define ConsoleView_h__

#include "IView.h"

#include <iostream>
#include <Windows.h>
using namespace std;

class ConsoleView : public IView
{
public:
	ConsoleView();
	~ConsoleView();

	void initialize(Game* game);

	void update();

	void clearHit();

	void showPauseTime(clock_t pauseStartTime);

	void clearPauseTime();

private:
	class Game* game;
	class Controller* controller;

	vector<vector<char> > map;

	static const int  VERTICAL_SIZE = 13, HORIZONTAL_SIZE = 49;

	void display();

	void showStatistics();

	void showEndMessage(bool isUserDefeat);

	void updateUserMap(vector<vector<int> > ships, vector<vector<int> > hits);
	void updateComputerMap(vector<vector<int> > ships, vector<vector<int> > hits);
};

#endif
