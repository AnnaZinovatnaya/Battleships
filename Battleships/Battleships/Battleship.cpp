#include "Game.h"
#include "IView.h"
#include "ConsoleView.h"
#include "Controller.h"

int main()
{
  Game game;

  IView * view = new ConsoleView();

  view->initialize(&game);

  Controller controller;
  controller.initialize(&game, view);

  controller.run();

  return 0;
}