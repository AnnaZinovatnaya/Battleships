#include "IGame.h"
#include "GameLogProxy.h"
#include "IView.h"
#include "ConsoleView.h"
#include "Controller.h"

int main()
{
  Game game;
  IGame * gameProxy = new GameLogProxy(game);

  IView * view = new ConsoleView();

  view->initialize(gameProxy);

  Controller controller;
  controller.initialize(gameProxy, view);

  controller.run();

  return 0;
}