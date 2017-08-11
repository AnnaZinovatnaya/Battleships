#include "Map.h"
#include <iostream>
using namespace std;


Map::Map()
{
	for (int i = 0; i < VERTICAL_SIZE; i++)
	{
		for (int j = 0; j < HORIZONTAL_SIZE; j++)
		{
			map[i][j] = ' ';
		}
	}
}



Map::~Map()
{
}



void Map::initialize(Player &human)
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

	for (int i = 0; i<FIELD_SIZE; i++)
	{
		for (int j = 0; j<FIELD_SIZE; j++)
		{
			if (human.ships[i][j] == 1)
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
	cout << "Press 'p' 3 times to pause the game";
	cout << "\n";
	cout << "\n";
	cout << "Type character and digit and press ENTER to hit:\n";

}

void Map::update(Player &human, Player &computer)
{
	DWORD dw;
	COORD here;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
	{
		printf("Invalid handle");
	}


	for (int i = 0; i<FIELD_SIZE; i++)
	{
		for (int j = 0; j<FIELD_SIZE; j++)
		{
			if (human.ships[i][j] == 1 && computer.hits[i][j] == 1)
			{
				map[i + 2][j + 3] = 'X';
				here.X = j + 3;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"X", 1, here, &dw);

			}

			if (human.ships[i][j] == 0 && computer.hits[i][j] == 1)
			{
				map[i + 2][j + 3] = '0';
				here.X = j + 3;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"0", 1, here, &dw);

			}

			if (computer.ships[i][j] == 1 && human.hits[i][j] == 1)
			{
				map[i + 2][j + 18] = 'X';
				here.X = j + 18;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"X", 1, here, &dw);

			}

			if (computer.ships[i][j] == 0 && human.hits[i][j] == 1)
			{
				map[i + 2][j + 18] = '0';
				here.X = j + 18;
				here.Y = i + 3;
				WriteConsoleOutputCharacter(hStdOut, L"0", 1, here, &dw);

			}
		}
	}
}

void Map::showEndMap(Player &human, Player &computer)
{
	system("cls");

	cout << "Game results:\n";

	for (int i = 0; i<FIELD_SIZE; i++)
	{
		for (int j = 0; j<FIELD_SIZE; j++)
		{

			if (computer.ships[i][j] == 1 && human.hits[i][j] == 0)
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