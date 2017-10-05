#ifndef Controller_h__
#define Controller_h__

#include <conio.h>

#include "IGame.h"
#include "IView.h"
#include <Windows.h>
#include <iostream>

#include <thread>


class Controller: public Observer
{
  public:

    Controller();
    ~Controller();

    void initialize(IGame* game, class IView* view);

    void update();

    void run();

  private:
    class IGame* game;
    class IView* view;

    bool isCorrectLetter(char letter) const;
    bool isCorrectDigit(char digit) const;

    void convertHumanHitToInt(vector<char> userInput, vector<int> &userHit) const;

    void handleUserHitEvent(vector<int> userHit) const;
};

#endif

