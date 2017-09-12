#include "Controller.h"



Controller::Controller()
{
}



Controller::~Controller()
{
}



void Controller::initialize(Game* game, IView* view)
{
  this->game = game;
  this->view = view;

  game->attach(this);
}



void Controller::update()
{
  stateType state = game->getState();

  if (state == STARTED || state == USER_TURN) {
    const int MAX_INPUT = 3;

    vector<char> userInput(MAX_INPUT, 0);

    cin.clear();
    userInput[0] = _getch();
    cout << userInput[0];
    if (userInput[0] == 'p') {
      //pause

		game->pause();
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
			view->clearHit();
            handleUserHitEvent(userHit);
          }
          else {
			  view->clearHit();
            this->update();
          }
        }
        else {
			view->clearHit();
          this->update();
        }
      }
      else {
		  view->clearHit();
        this->update();
      }
    }
  }
  else if (state == COMPUTER_TURN) {
  }
  else if (state == PAUSED) {
    //wait for space (end of pause)

	clock_t pauseStartTime = game->getPauseStartTime();

	const char SPACE = ' ';

	int oldTime = (clock() - pauseStartTime) / CLOCKS_PER_SEC;
	view->showPauseTime(oldTime);

	while (!(GetKeyState(SPACE) & 0x8000))
	{

		int newTime = (clock() - pauseStartTime) / CLOCKS_PER_SEC;

		if (newTime != oldTime)
		{
			view->showPauseTime(newTime);

			oldTime = newTime;
		}
	} 

	view->clearPauseTime();
	game->stopPause();
  }
  else if (state == ENDED) {
    const char ENTER = '\r';
    while (_getch() != ENTER) {}
  }
}



void Controller::run()
{
  const char ENTER = '\r';

  while (_getch() != ENTER) {}

  game->play();
}



bool Controller::isCorrectLetter(char letter) const
{
  if (letter >= 'a' && letter <= 'j')
    return true;

  if (letter >= 'A' && letter <= 'J')
    return true;

  return false;
}



bool Controller::isCorrectDigit(char digit) const
{
  if (digit >= '0' && digit <= '9')
    return true;

  return false;
}



void Controller::convertHumanHitToInt(vector<char> userInput, vector<int> &userHit) const
{

  if (userInput[0] >= 'A' && userInput[0] <= 'J')
    userHit[0] = userInput[0] % 'A';
  else
    userHit[0] = userInput[0] % 'a';

  userHit[1] = userInput[1] % '0';
}



void Controller::handleUserHitEvent(vector<int> userHit) const
{
  game->hit(userHit);
}