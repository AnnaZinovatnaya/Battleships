#include "Game.h"

Game::Game(void)
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

	cout << "\n";
	cout << " Please wait until the game is loaded...";

	Game::human.initialize();
	Game::computer.initialize();

	Game::map.initializeMap(human.ships);
}



Game::~Game(void)
{
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

	clock_t startTime = clock();

	while (endOfGame == false) 
	{	
		cHit[0] = _getch();
		putchar(cHit[0]);
		cHit[1] = _getch();
		putchar(cHit[1]);
		cHit[2] = _getch();
		putchar(cHit[2]);

		Game::setCursorPosition(0, 18);

		cout << "   \b\b\b";

		properHit = Game::checkHit(cHit);
		if (properHit) 
		{
			Game::convertHumanHitToInt(cHit, humanHit);
			Game::human.hit(humanHit);
			Game::map.updateMap(human.ships, human.hits, computer.ships, computer.hits);

			isComputerSinkSunk = Game::computer.markSunkShips(human.hits);
			if (isComputerSinkSunk) 
			{
				cout << "\nYou sunk enemy's ship!" << endl;
				Sleep(1500);
				Game::setCursorPosition(0, 19);

				cout << "                      ";

				Game::setCursorPosition(0, 18);
				
				endOfGame = Game::checkEndOfGame();
			}
			
			if (endOfGame == true)
				break;

			Game::computer.hit();
			Game::map.updateMap(human.ships, human.hits, computer.ships, computer.hits);

			isAnyHumanShipHit = Game::human.isAnyShipHit(computer.getLastHitX(), 
					computer.getLastHitY());

			if (isAnyHumanShipHit)
			{
				computer.markSuccessHit();
				isHumanSinkSunk = Game::human.markSunkShips(computer.hits);
				if (isHumanSinkSunk) 
				{
					computer.markSunkShip();
					endOfGame = Game::checkEndOfGame();
				}
			}
			else 
			{
				computer.markMissedHit();
			}

			if (endOfGame == true)
				break;
		}
		else
		{
			if (cHit[0] == 'p' && cHit[1] == 'p' && cHit[2] == 'p') 
			{
				Game::pause();
			}
		}
		if (endOfGame == true)
			break;
	}

	clock_t endTime = clock();
	timeOfGame = static_cast<int>(endTime - startTime) / CLOCKS_PER_SEC;

	Game::map.showEndMap(human.ships, human.hits, computer.ships, computer.hits);

	if (human.getIsDeafeat() == true) 
	{
		Game::showEndMessage(losingMessage);
	}
	else 
	{
		Game::showEndMessage(winningMessage);
	}

	Game::showStatistics();

	cout << "\nPress ENTER to exit...";
	keyPressed = 0;
	while (keyPressed != '\r')
	{
		keyPressed = _getch();
	}
}



void Game::convertHumanHitToInt(char cHit[3], int humanHit[2])
{
	switch (cHit[0]) {
		case 'A' : case 'a' : humanHit[0] = 0; break;
		case 'B' : case 'b' : humanHit[0] = 1; break;
		case 'C' : case 'c' : humanHit[0] = 2; break;
		case 'D' : case 'd' : humanHit[0] = 3; break;
		case 'E' : case 'e' : humanHit[0] = 4; break;
		case 'F' : case 'f' : humanHit[0] = 5; break;
		case 'G' : case 'g' : humanHit[0] = 6; break;
		case 'H' : case 'h' : humanHit[0] = 7; break;
		case 'I' : case 'i' : humanHit[0] = 8; break;
		case 'J' : case 'j' : humanHit[0] = 9;
	}

	switch (cHit[1]) {
		case '0' : humanHit[1] = 0; break;
		case '1' : humanHit[1] = 1; break;
		case '2' : humanHit[1] = 2; break;
		case '3' : humanHit[1] = 3; break;
		case '4' : humanHit[1] = 4; break;
		case '5' : humanHit[1] = 5; break;
		case '6' : humanHit[1] = 6; break;
		case '7' : humanHit[1] = 7; break;
		case '8' : humanHit[1] = 8; break;
		case '9' : humanHit[1] = 9;
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
	if (hit[0] >= 'a'&&hit[0] <= 'j') 
		return true;

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
	int minutes = static_cast<int>(timeOfGame / 60);
	int humanSunkShips = human.countSunkShips();
	int computerSunkShips = computer.countSunkShips();

	cout << "\n";
	cout << "Statistics:";
	cout << "\n";
	cout << "\n";
	cout << "Time: " << minutes << " minute(s) ";
	cout<< timeOfGame - (minutes * 60) << " second(s)" << endl;
	cout << "\n";
	cout << "You sunk " << computerSunkShips << " of enemy's ships" << endl;
	cout << "\n";
	cout << "Enemy sunk " << humanSunkShips << " of your ships" << endl;
}



void Game::showEndMessage(char message[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE]){

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



bool Game::listenKeyPress(short p_key)
{
	const unsigned short MSB = 0x8000;

	if (GetAsyncKeyState(p_key) & MSB)
	{
		return true;
	}

	else return false;
}



void Game::pause(void)
{
	clock_t startTime = clock();
	clock_t endTime;
	int oldTime = 0;
	int newTime = 0;
	int minutes = 0;

	cout << "\n";
	cout << "PAUSED Press SPACE key to continue... " << endl;
	cout<<"Time: 0 minute(s) 0 second(s)";

	while (!listenKeyPress(VK_SPACE))
	{
		endTime = clock();
		newTime = static_cast<int>(endTime - startTime) / CLOCKS_PER_SEC;
		if (newTime != oldTime) {

			Game::setCursorPosition(0, 20);
			cout << "                               ";
			Game::setCursorPosition(0, 20);

			minutes = static_cast<int>(newTime / 60);
			cout << "Time: " << minutes << " minute(s) ";
			cout<< newTime - (minutes * 60) << " second(s)" << endl;
			oldTime = newTime;
		}
	}

	Game::setCursorPosition(0, 19);

	for (int i = 0; i<8; i++) 
	{
		cout << "                    ";
	}

	Game::setCursorPosition(0, 18);
}



void Game::setCursorPosition(int column, int row)
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}