#include "ConsoleView.h"



ConsoleView::ConsoleView()
{
	cout << "\n";
	cout << " *************************************" << endl;
	cout << " *                                   *" << endl;
	cout << " *      Welcome to BATTLESHIPS!      *" << endl;
	cout << " *                                   *" << endl;
	cout << " *************************************" << endl;
	cout << "\n\n";
	cout << " Press ENTER to start...";
}


ConsoleView::~ConsoleView()
{
}

void ConsoleView::initialize(Model* model)
{
	char tempMap[VERTICAL_SIZE][HORIZONTAL_SIZE] = {
		"   0123456789     0123456789 ",
		"  #----------#   #----------#",
		" A|          |  A|          |",
		" B|          |  B|          |",
		" C|          |  C|          |",
		" D|          |  D|          |",
		" E|          |  E|          |",
		" F|          |  F|          |",
		" G|          |  G|          |",
		" H|          |  H|          |",
		" I|          |  I|          |",
		" J|          |  J|          |",
		"  #----------#   #----------#" };

	vector<char> row(HORIZONTAL_SIZE, '0');
	vector<vector<char> > map(VERTICAL_SIZE, row);
	
	
	for (int i = 0; i < map.size(); i++) {

		for (int j = 0; j < map[i].size(); j++)

			map[i][j] = tempMap[i][j];
	}



	this->model = model;
	model->attach(this);


	vector<vector<int> > userShips = model->getUserShips();

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {
			if (userShips[i][j] == 1) {
				map[i + 2][j + 3] = 'S';
			}
		}
	}

	this->map = map;

}



void ConsoleView::display()
{
	stateType state = model->getState();

	if (state == STARTED) {

		system("cls");

		for (int i = 0; i < map.size(); i++) {

			for (int j = 0; j < map[i].size(); j++) {
				cout << map[i][j];
			}
			cout << endl;
		}


		cout << "\n";
		cout << "Press 'p' to pause the game";
		cout << "\n";
		cout << "\n";
		cout << "Type character and digit and press ENTER to hit:\n";
	}
	else if (state == COMPUTER_TURN) {
		//update computer map
	}
	else if (state == USER_TURN) {
		//update user map
	}
	else if (state == PAUSED) {
		//show pause time
	}
	else if (state == ENDED) {
		bool isUserDefeat = model->isUserDefeat();

		showEndMessage(isUserDefeat);

		showStatistics();

		cout << "\n";
		cout << "Press ENTER to exit...";
	}
}

void ConsoleView::update()
{
	display();
}

void ConsoleView::clearHit()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 17});
	cout << "  ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 17 });
}



void ConsoleView::showStatistics()
{
	int timeOfGame = model->getTimeOfGame();
	int computerSunkShips = model->countComputerSunkShips();
	int userSunkShips = model->countUserSunkShips();

	int minutes = static_cast<int>(timeOfGame / 60);

	cout << "\n";
	cout << "Statistics:" << endl;
	cout << "\n";
	cout << "Time: " << minutes << " minute(s) ";
	cout << timeOfGame - (minutes * 60) << " second(s)" << endl;
	cout << "\n";
	cout << "You sunk " << computerSunkShips << " of enemy's ships" << endl;
	cout << "\n";
	cout << "Enemy sunk " << userSunkShips << " of your ships" << endl;
}



void
ConsoleView::showEndMessage(bool isUserDefeat) {

	char winningMessage[5][25] = {
		"                        ",
		" ***********************",
		" *      YOU WON!       *",
		" ***********************",
		"                        " };

	char losingMessage[5][25] = {
		"                        ",
		" ***********************",
		" *     YOU LOST :(     *",
		" ***********************",
		"                        " };


	cout << "\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (isUserDefeat) {
				cout << losingMessage[i][j];
			}
			else {
				cout << winningMessage[i][j];
			}
		}
		cout << "\n";
	}
}
