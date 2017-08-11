#include "Model.h"
#include "ConsoleView.h"

int main() {

	Model model;

	ConsoleView consoleView;

	consoleView.initialize(&model);

	return 0;
}