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

	if (state == STARTED || state == USER_TURN) {
		vector<char> userInput(3, 0);
		
		userInput[0] = _getch();
		cout << userInput[0];
		if (userInput[0] == 'p') {
			//pause
		}
		else {
			userInput[1] = _getch();
			cout << userInput[1];

			userInput[2] = _getch();

			if (isCorrectLetter(userInput[0])) {

				if (isCorrectDigit(userInput[1])) {

					if (userInput[2] == '\r') {

						vector<int> userHit = { 0, 0 };
						convertHumanHitToInt(userInput, userHit);
						consoleView->clearHit();
						handleUserHitEvent(userHit);

					}
					else {
						consoleView->clearHit();
						this->update();
					}
				}
				else {
					consoleView->clearHit();
					this->update();
				}
			}
			else {
				consoleView->clearHit();
				this->update();
			}

			
		}
	}
	else if (state == COMPUTER_TURN)
	{
	}

	else if (state == PAUSED) {
		//wait for space (end of pause)
	}
	else if (state == ENDED) {
		//wait for ENTER to close window
	}
}


void Controller::run()
{
	const char ENTER = '\r';

	while (_getch() != ENTER) {}

	model->play();


}

bool Controller::isCorrectLetter(char letter)
{
	if (letter >= 'a' && letter <= 'j')
		return true;

	if (letter >= 'A' && letter <= 'J')
		return true;

	return false;
}

bool Controller::isCorrectDigit(char digit)
{
	if (digit >= '0' && digit <= '9')
		return true;

	return false;
}



void Controller::convertHumanHitToInt(vector<char> userInput, vector<int> &userHit) const
{

	if (userInput[0] >= 'A' && userInput[0] <= 'J')
	{
		userHit[0] = userInput[0] % 'A';
	}
	else
	{
		userHit[0] = userInput[0] % 'a';
	}

	userHit[1] = userInput[1] % '0';
}

void Controller::handleUserHitEvent(vector<int> userHit)
{
	model->hit(userHit);
}
