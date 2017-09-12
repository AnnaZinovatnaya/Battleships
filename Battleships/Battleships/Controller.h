#ifndef Controller_h__
#define Controller_h__

#include <conio.h>

#include "Game.h"
#include "IView.h"
#include <Windows.h>

#include <thread>


class Controller: public Observer
{
  public:

    Controller();
    ~Controller();

    void initialize(Game* game, class IView* view);

    void update();

    void run();

  private:
    class Game* game;
    class IView* view;

    bool isCorrectLetter(char letter) const;
    bool isCorrectDigit(char digit) const;

    void convertHumanHitToInt(vector<char> userInput, vector<int> &userHit) const;

    void handleUserHitEvent(vector<int> userHit) const;
};

#endif

