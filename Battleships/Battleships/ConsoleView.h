#ifndef View_h__
#define View_h__

#include <iostream>
using namespace std;

#include "Observer.h"
#include "Game.h"
#include "Controller.h"

class ConsoleView : public Observer
{
public:
	ConsoleView();
	~ConsoleView();

	void initialize(Game* game);

	void update();

	void clearHit();

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

