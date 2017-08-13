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

	void update();

	void run();

	bool isCorrectLetter(char letter);

	bool isCorrectDigit(char digit);

	void convertHumanHitToInt(vector<char> userInput, vector<int> &userHit) const;

	void handleUserHitEvent(vector<int> userHit);
};

#endif

