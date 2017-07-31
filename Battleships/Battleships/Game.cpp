#include "Game.h"

Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::initializeGame(void)
{
	char keyPressed = 0;

	cout << "\n";
	cout << " *************************************" << endl;
	cout << " *                                   *" << endl;
	cout << " *      Welcome to BATTLESHIPS!      *" << endl;
	cout << " *                                   *" << endl;
	cout << " *************************************" << endl;
	cout << "\n\n";
	cout << " Press ENTER to start...";

	while (keyPressed != '\r')
	{
		keyPressed = _getch();
	}
	system("cls");

	cout << "Please wait until the game is loaded...";

	Game::human.initialize();
	Game::computer.initialize();

	Game::map.initializeMap(human.ships);
}

void Game::playGame(void)
{
	char cHit[3] = "00";
	int humanHit[2] = { 0,0 };
	int computerHit[2] = { 0,0 };
	bool properHit = false;
	bool endOfGame = false;
	char keyPressed = 0;
	bool isComputerSinkSunk = false;
	bool isHumanSinkSunk = false;
	bool isAnyHumanShipHit = false;

	char winningMessage[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE] = {
		"                        ",
		" ***********************",
		" *      YOU WON!       *",
		" ***********************",
		"                        " };

	char losingMessage[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE] = {
		"                        ",
		" ***********************",
		" *     YOU LOST :(     *",
		" ***********************",
		"                        " };

	clock_t t0 = clock();

	while (endOfGame == false) {


		
		cHit[0] = _getch();
		putchar(cHit[0]);
		cHit[1] = _getch();
		putchar(cHit[1]);
		cHit[2] = _getch();
		putchar(cHit[2]);

		COORD coord;
		coord.X = 0;
		coord.Y = 18;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		cout << "   \b\b\b";

		properHit = Game::checkHit(cHit);
		if (properHit) {

			Game::convertHumanHit(cHit, humanHit);
			Game::human.hit(humanHit);
			//Game::computer.markSunkShips(human.hits);
			Game::map.updateMap(human.ships, human.hits, computer.ships, computer.hits);

			isComputerSinkSunk = Game::computer.markSunkShips(human.hits);
			if (isComputerSinkSunk) {
				cout << "\nYou sunk enemy's ship!" << endl;
				Sleep(2000);
				coord.X = 0;
				coord.Y = 19;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

				cout << "                      ";

				coord.X = 0;
				coord.Y = 18;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

			}
			

			endOfGame = Game::checkEndOfGame();
			if (endOfGame == true)
				break;

			Game::computer.hit();
			Game::map.updateMap(human.ships, human.hits, computer.ships, computer.hits);

			isAnyHumanShipHit = Game::human.isAnyShipHit(computer.lastHitX, computer.lastHitY);
			if (isAnyHumanShipHit)
			{
				computer.markSuccessHit();
				isHumanSinkSunk = Game::human.markSunkShips(computer.hits);
				if (isHumanSinkSunk) {
					computer.markSunkShip();
				}
			}
			else {
				computer.markMissedHit();
			}

			endOfGame = Game::checkEndOfGame();
			if (endOfGame == true)
				break;
		}
		else
		{
			if (cHit[0] == 'p' && cHit[1] == 'p' && cHit[2] == 'p') {
				Game::pauseGame();
			}
		}
		if (endOfGame == true)
			break;
	}

	clock_t t1 = clock();
	timeOfGame = static_cast<int>(t1 - t0) / CLOCKS_PER_SEC;

	Game::map.showEndMap(human.ships, human.hits, computer.ships, computer.hits);

	if (human.defeatFlag == true) {
		Game::showMessage(losingMessage);
	}
	else {
		Game::showMessage(winningMessage);
	}

	Game::showStatistics();

	cout << "\nPress ENTER to exit...";
	keyPressed = 0;
	while (keyPressed != '\r')
	{
		keyPressed = _getch();
	}
}

bool Game::checkHit(char hit[3])
{
	if (hit[2] != '\r')
		return false;
	if (hit[1]<'0' || hit[1]>'9')
		return false;
	if (hit[0] >= 'A'&&hit[0] <= 'J')
		return true;
	if (hit[0] >= 'a'&&hit[0] <= 'j') {
		return true;
	}

	return false;
}


bool Game::checkEndOfGame(void)
{
	bool humanShipsKilled = false;
	bool computerShipsKilled = false;

	humanShipsKilled = human.checkEndOfGame();
	if (humanShipsKilled == true)
		return true;

	computerShipsKilled = computer.checkEndOfGame();
	if (computerShipsKilled == true)
		return true;

	return false;
}

void Game::showStatistics(void)
{
	cout << "\n";
	cout << "Statistics:";
	cout << "\n";
	cout << "\n";
	int minutes = static_cast<int>(timeOfGame / 60);
	cout << "Time: " << minutes << " minutes " << timeOfGame - (minutes * 60) << " seconds" << endl;
	cout << "\n";
	cout << "You sunk " << computer.countSunkShips() << " of enemy's ships" << endl;
	cout << "\n";
	cout << "Emeny sunk " << human.countSunkShips() << " of your ships" << endl;
}

void Game::showMessage(char message[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE]) {

	cout << "\n";
	for (int i = 0; i < MSG_VERTICAL_SIZE; i++)
	{
		for (int j = 0; j < MSG_HORIZONTALAL_SIZE; j++)
		{
			cout << message[i][j];
		}
		cout << "\n";
	}
}

void Game::convertHumanHit(char cHit[3], int humanHit[2])
{
	if (cHit[0] >= 'A'&&cHit[0] <= 'J') {
		humanHit[0] = cHit[0] % 65;
	}
	else {
		humanHit[0] = cHit[0] % 97;
	}

	humanHit[1] = cHit[1] % 48;
}

bool Game::listenKeyPress(short p_key)
{

	const unsigned short MSB = 0x8000;

	if (GetAsyncKeyState(p_key) & MSB)
	{
		return true;
	}

	else return false;
}

void Game::pauseGame(void)
{
	COORD coord;
	clock_t pause0 = clock();
	clock_t pause1;
	int oldTime = 0;
	int newTime = 0;
	int minutes = 0;
	cout << "\n";
	cout << "PAUSED Press SPACE key to continue... \nTime: 0 minute(s) 0 second(s)";
	while (!listenKeyPress(VK_SPACE))
	{
		pause1 = clock();
		newTime = static_cast<int>(pause1 - pause0) / CLOCKS_PER_SEC;
		if (newTime != oldTime) {

			coord.X = 0;
			coord.Y = 20;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << "                               ";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

			int minutes = static_cast<int>(newTime / 60);
			cout << "Time: " << minutes << " minute(s) " << newTime - (minutes * 60) << " second(s)" << endl;
			oldTime = newTime;
		}

	}

	coord.X = 0;
	coord.Y = 18;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	for (int i = 0; i<8 * 7; i++) {
		cout << "          ";
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}