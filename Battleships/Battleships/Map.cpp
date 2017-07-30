#include "Map.h"
#include <iostream>
using namespace std;


Map::Map(void)
{
}


Map::~Map(void)
{
}

void Map::initializeMap(int humanShips[10][10])
{
	system("cls");

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

	for (int i = 0; i < VERTICAL_SIZE; i++)
	{
		for (int j = 0; j < HORIZONTAL_SIZE; j++)
		{
			map[i][j] = tempMap[i][j];
		}
	}



	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (humanShips[i][j] == 1)
			{
				map[i + 2][j + 3] = 'S';
			}
		}
	}



	cout << "\n";
	for (int i = 0; i < VERTICAL_SIZE; i++)
	{
		for (int j = 0; j < HORIZONTAL_SIZE; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "Press 'p', then ENTER to pause the game";
	cout << "\n";
	cout << "\n";
	cout << "Type character and digit and press ENTER to hit:\n";

}

void Map::updateMap(int humanShips[10][10], int humanHits[10][10], int computerShips[10][10], int computerHits[10][10])
{
	DWORD dw;
	COORD here;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
	{
		printf("Invalid handle");
	}


	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (humanShips[i][j] == 1 && computerHits[i][j] == 1)
			{
				map[i + 2][j + 3] = 'X';
				here.X = j + 3;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"X", 1, here, &dw);

			}

			if (humanShips[i][j] == 0 && computerHits[i][j] == 1)
			{
				map[i + 2][j + 3] = '0';
				here.X = j + 3;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"0", 1, here, &dw);

			}

			if (computerShips[i][j] == 1 && humanHits[i][j] == 1)
			{
				map[i + 2][j + 18] = 'X';
				here.X = j + 18;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"X", 1, here, &dw);

			}

			if (computerShips[i][j] == 0 && humanHits[i][j] == 1)
			{
				map[i + 2][j + 18] = '0';
				here.X = j + 18;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"0", 1, here, &dw);

			}
		}
	}
}


void Map::showEndMap(int humanShips[10][10], int humanHits[10][10], int computerShips[10][10], int computerHits[10][10])
{
	system("cls");

	cout << "Game results:\n";

	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{

			if (computerShips[i][j] == 1 && humanHits[i][j] == 0)
			{
				map[i + 2][j + 18] = 'S';
			}
		}
	}

	cout << "\n";
	for (int i = 0; i < VERTICAL_SIZE; i++)
	{
		for (int j = 0; j < HORIZONTAL_SIZE; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}