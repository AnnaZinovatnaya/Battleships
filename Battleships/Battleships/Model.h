#ifndef Model_h__
#define Model_h__

#include <list>
using namespace std;

#include "Observer.h"
#include "Map.h"
#include "Player.h"
#include "ComputerPlayer.h"

class Model
{
public:
	list <Observer*> observers;

	Player human;
	ComputerPlayer computer;
	int timeOfGame;


	Model();
	~Model();

	void attach(Observer* observer);
	void detach(Observer* observer);

	void notify();
	void getData();
	void service();

	void play();
	bool checkEndOfGame();
	void pause() const;
	
};

#endif

