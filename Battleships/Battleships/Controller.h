#ifndef Controller_h__
#define Controller_h__

#include <conio.h>

#include "Game.h"
#include "ConsoleView.h"

class Controller: public Observer
{
  public:

    Controller();
    ~Controller();

    void initialize(Game* game, class ConsoleView* consoleView);

    void update();

    void run();

  private:
    class Game* game;
    class ConsoleView* consoleView;

    bool isCorrectLetter(char letter) const;

    bool isCorrectDigit(char digit) const;

    void convertHumanHitToInt(vector<char> userInput, vector<int> &userHit) const;

    void handleUserHitEvent(vector<int> userHit) const;
};

#endif

