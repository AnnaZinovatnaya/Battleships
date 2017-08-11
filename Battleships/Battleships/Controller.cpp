#include "Controller.h"



Controller::Controller()
{
}


Controller::~Controller()
{
}


void Controller::initialize(Model* model, ConsoleView* consoleView)
{
	this->model = model;
	this->consoleView = consoleView;

	model->attach(this);
}



void Controller::update()
{
	stateType state = model->getState();

	if (state == STARTED) {
		vector<char> userInput(3, 0);
		
		userInput[0] = _getch();
		if (userInput[0] == 'p') {
			handlePauseEvent();
		}
	}
	else if (state == PAUSED) {
		for (int i = 0; i < 1000; i++) {
			const unsigned short MSB = 0x8000;

			if (GetAsyncKeyState(VK_SPACE) & MSB)
			{
				handleEndPauseEvent();
			}
		}
	}
}

void Controller::handlePauseEvent()
{
	model->pause();
}


void Controller::handleEndPauseEvent()
{
	model->endPause();
}


void Controller::run()
{
	const char ENTER = '\r';

	while (_getch() != ENTER) {}

	model->play();


}
