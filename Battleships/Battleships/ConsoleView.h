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
	Model* model;

	ConsoleView();
	~ConsoleView();

	void initialize(Model* model);

	void activate();
	void display();
	void update();

	
};

#endif

