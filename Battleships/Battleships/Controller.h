#ifndef Controller_h__
#define Controller_h__

#include <conio.h>

#include "Model.h"
#include "ConsoleView.h"

class Controller: public Observer
{
public:
	class Model* model;
	class ConsoleView* consoleView;

	Controller();
	~Controller();

	void initialize(Model* model, ConsoleView* consoleView);
	void handleEvent();
	void update();

};

#endif

