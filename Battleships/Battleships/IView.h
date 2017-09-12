#ifndef IView_h__
#define IView_h__

#include "Observer.h"
#include "Game.h"
#include "Controller.h"

class IView : public Observer
{
public:
	IView();
	virtual ~IView();

	virtual void initialize(Game* game) = 0;

	virtual void update() = 0;

	virtual void clearHit() = 0;

protected:
	class Game* game;
	class Controller* controller;

	vector<vector<char> > map;

	static const int  VERTICAL_SIZE = 13, HORIZONTAL_SIZE = 49;

	virtual void display() = 0;

	virtual void showStatistics() = 0;

	virtual void showEndMessage(bool isUserDefeat) = 0;

	virtual void updateUserMap(vector<vector<int> > ships, vector<vector<int> > hits) = 0;
	virtual void updateComputerMap(vector<vector<int> > ships, vector<vector<int> > hits) = 0;
};

#endif