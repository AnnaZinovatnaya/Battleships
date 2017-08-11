#include "Model.h"
#include "ConsoleView.h"

int main() {

	Model model;

	ConsoleView consoleView;
	consoleView.initialize(&model);

	Controller controller;
	controller.initialize(&model, &consoleView);

	controller.run();

	return 0;
}