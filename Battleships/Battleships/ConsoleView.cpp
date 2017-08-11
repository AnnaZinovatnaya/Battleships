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

	this->map = map;

	this->model = model;
	model->attach(this);

}



void ConsoleView::display()
{
	stateType state = model->getState();

	if (state == STARTED) {

		system("cls");

		vector<vector<int> > userShips = model->getUserShips();

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {
				if (userShips[i][j] == 1) {
					map[i + 2][j + 3] = 'S';
				}
			}
		}

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
	else if (state == PAUSED) {
		int pausedTime = model->getPauseTime();
		if (pausedTime == 0) {
			cout << "\n";
			cout << "PAUSED Press SPACE key to continue... " << endl;
			cout << "Time: 0 minute(s) 0 second(s)";
		}
		else {

			static const int COLUMN_POSITION_FOR_PAUSE_TIME = 0;
			static const int ROW_POSITION_FOR_PAUSE_TIME = 19;
		
			setCursorPosition(COLUMN_POSITION_FOR_PAUSE_TIME,
				ROW_POSITION_FOR_PAUSE_TIME);

			int minutes = static_cast<int>(pausedTime / 60);
			cout << "Time: " << minutes << " minute(s) ";
			cout << pausedTime - (minutes * 60) << " second(s)" << endl;
		}

	}
}

void ConsoleView::update()
{
	display();
}



void ConsoleView::setCursorPosition(int column, int row) const
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
