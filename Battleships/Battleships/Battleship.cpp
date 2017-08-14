#include "Game.h"
#include "ConsoleView.h"

int main() {

	Game game;

	ConsoleView consoleView;
	consoleView.initialize(&game);

	Controller controller;
	controller.initialize(&game, &consoleView);

	controller.run();

	return 0;
}