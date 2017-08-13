#ifndef View_h__
#define View_h__

#include <iostream>
using namespace std;

#include "Observer.h"
#include "Model.h"
#include "Controller.h"

class ConsoleView : public Observer
{
public:
	class Model* model;
	class Controller* controller;

	vector<vector<char> > map;
	static const int  VERTICAL_SIZE = 13, HORIZONTAL_SIZE = 49;

	ConsoleView();
	~ConsoleView();

	void initialize(Model* model);

	void display();
	void update();

	void clearHit();

	void showStatistics();

	void showEndMessage(bool isUserDefeat);

	void updateUserMap(vector<vector<int> > ships, vector<vector<int> > hits);
	void updateComputerMap(vector<vector<int> > ships, vector<vector<int> > hits);
};

#endif

