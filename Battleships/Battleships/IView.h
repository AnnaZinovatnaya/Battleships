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

	virtual void showPauseTime(clock_t pauseStartTime) = 0;

	virtual void clearPauseTime() = 0;

protected:

	virtual void display() = 0;

	virtual void showStatistics() = 0;

	virtual void showEndMessage(bool isUserDefeat) = 0;

	virtual void updateUserMap(vector<vector<int> > ships, vector<vector<int> > hits) = 0;
	virtual void updateComputerMap(vector<vector<int> > ships, vector<vector<int> > hits) = 0;
};

#endif