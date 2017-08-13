#include "Game.h"


Game::Game()
{
	srand(time(0));

	cout << "\n";
	cout << " *************************************" << endl;
	cout << " *                                   *" << endl;
	cout << " *      Welcome to BATTLESHIPS!      *" << endl;
	cout << " *                                   *" << endl;
	cout << " *************************************" << endl;
	cout << "\n\n";
	cout << " Press ENTER to start...";

	waitForEnterPressed();

	user.initialize();
	computer.initialize();

	map.initialize(user);

	timeOfGame = 0;
}



Game::~Game()
{
}



void Game::playGame()
{
	char charHumanHit[3] = { "00" };
	int humanHit[2] = { 0,0 };
	bool properHit = false;

	int computerHit[2] = { 0,0 };
	
	bool endOfGame = false;

	bool isAnyHumanShipHit = false;
	bool isHumanShipSunk = false;

	bool isComputerShipSunk = false;

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
		charHumanHit[0] = _getch();
		putchar(charHumanHit[0]);

		charHumanHit[1] = _getch();
		putchar(charHumanHit[1]);

		charHumanHit[2] = _getch();
		putchar(charHumanHit[2]);

		setCursorPosition(COLUMN_POSITION_FOR_USER_HIT, 
			ROW_POSITION_FOR_USER_HIT);

		cout << "   ";

		setCursorPosition(COLUMN_POSITION_FOR_USER_HIT,
			ROW_POSITION_FOR_USER_HIT);

		properHit = checkHumanHit(charHumanHit);

		if (properHit) 
		{
			convertHumanHitToInt(charHumanHit, humanHit);
			//user.hit(humanHit);

			map.update(user, computer);

			isComputerShipSunk = computer.markSunkShips(user.hits);
			if (isComputerShipSunk) 
			{
				cout << "\nYou sunk enemy's ship!" << endl;
				Sleep(1500);
				setCursorPosition(COLUMN_POSITION_FOR_USER_HIT,
					ROW_POSITION_FOR_USER_HIT+1);

				cout << "                      ";

				setCursorPosition(COLUMN_POSITION_FOR_USER_HIT, 
					ROW_POSITION_FOR_USER_HIT);
				
				endOfGame = checkEndOfGame();
			}
			
			if (endOfGame)
				break;

			computer.hit();

			map.update(user, computer);

			isAnyHumanShipHit = user.isAnyShipHit(computer.getLastHitX(), 
					computer.getLastHitY());

			if (isAnyHumanShipHit)
			{
				computer.markSuccessHit();

				isHumanShipSunk = user.markSunkShips(computer.hits);
				if (isHumanShipSunk) 
				{
					computer.markSunkShip();
					endOfGame = checkEndOfGame();
				}
			}
			else 
			{
				computer.markMissedHit();
			}

			if (endOfGame)
				break;
		}
		else
		{
			if (charHumanHit[0] == 'p' && charHumanHit[1] == 'p' && charHumanHit[2] == 'p') 
			{
				pause();
			}
		}
	}

	clock_t endTime = clock();
	timeOfGame = static_cast<int>(endTime - startTime) / CLOCKS_PER_SEC;

	map.showEndMap(user, computer);

	if (user.getIsDeafeat()) 
	{
		showEndMessage(losingMessage);
	}
	else 
	{
		showEndMessage(winningMessage);
	}

	showStatistics();

	cout << "\n";
	cout << "Press ENTER to exit...";

	waitForEnterPressed();
}



void Game::convertHumanHitToInt(char cHit[3], int humanHit[2]) const
{

	if (cHit[0] >= 'A' && cHit[0] <= 'J')
	{
		humanHit[0] = cHit[0] % 'A';
	}
	else
	{
		humanHit[0] = cHit[0] % 'a';
	}

	humanHit[1] = cHit[1] % '0';
}



bool Game::checkHumanHit(char hit[3]) const
{
	const char ENTER_KEY = '\r';

	if (hit[2] != ENTER_KEY)
		return false;
	if (hit[1] < '0' || hit[1] > '9')
		return false;
	if (hit[0] >= 'A' && hit[0] <= 'J')
		return true;
	if (hit[0] >= 'a' && hit[0] <= 'j') 
		return true;

	return false;
}



bool Game::checkEndOfGame()
{
	bool humanShipsKilled = user.checkEndOfGame();
	if (humanShipsKilled)
		return true;

	bool computerShipsKilled = computer.checkEndOfGame();
	if (computerShipsKilled)
		return true;

	return false;
}



void Game::showStatistics()
{
	int minutes = static_cast<int>(timeOfGame / 60);

	cout << "\n";
	cout << "Statistics:"<< endl;
	cout << "\n";
	cout << "Time: " << minutes << " minute(s) ";
	cout<< timeOfGame - (minutes * 60) << " second(s)" << endl;
	cout << "\n";
	cout << "You sunk " << computer.countSunkShips() << " of enemy's ships" << endl;
	cout << "\n";
	cout << "Enemy sunk " << user.countSunkShips() << " of your ships" << endl;
}



void 
Game::showEndMessage(char message[MSG_VERTICAL_SIZE][MSG_HORIZONTALAL_SIZE]){

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



bool Game::listenKeyPress(short p_key) const
{
	const unsigned short MSB = 0x8000;

	if (GetAsyncKeyState(p_key) & MSB)
	{
		return true;
	}

	else return false;
}



void Game::pause() const
{
	clock_t startTime = clock();
	clock_t endTime = clock();

	int oldTime = 0;
	int newTime = 0;

	static const int COLUMN_POSITION_FOR_PAUSE_TIME = 0;
	static const int ROW_POSITION_FOR_PAUSE_TIME = 20;

	cout << "\n";
	cout << "PAUSED Press SPACE key to continue... " << endl;
	cout<<"Time: 0 minute(s) 0 second(s)";

	while (!listenKeyPress(VK_SPACE))
	{
		endTime = clock();
		newTime = static_cast<int>(endTime - startTime) / CLOCKS_PER_SEC;
		if (newTime != oldTime) {

			setCursorPosition(COLUMN_POSITION_FOR_PAUSE_TIME, 
				ROW_POSITION_FOR_PAUSE_TIME);

			cout << "                               ";

			setCursorPosition(COLUMN_POSITION_FOR_PAUSE_TIME, 
				ROW_POSITION_FOR_PAUSE_TIME);

			int minutes = static_cast<int>(newTime / 60);
			cout << "Time: " << minutes << " minute(s) ";
			cout<< newTime - (minutes * 60) << " second(s)" << endl;
			oldTime = newTime;
		}
	}

	setCursorPosition(COLUMN_POSITION_FOR_USER_HIT,
		ROW_POSITION_FOR_USER_HIT+1);

	for (int i = 0; i<8; i++) 
	{
		cout << "                    ";
	}

	setCursorPosition(COLUMN_POSITION_FOR_USER_HIT, 
		ROW_POSITION_FOR_USER_HIT);
}



void Game::setCursorPosition(int column, int row) const
{
	COORD coord;
	coord.X = column;
	coord.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Game::waitForEnterPressed() const
{
	char keyPressed = 0;
	static const char ENTER_KEY = '\r';

	while (keyPressed != ENTER_KEY)
	{
		keyPressed = _getch();
	}
}