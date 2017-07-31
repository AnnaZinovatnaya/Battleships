#pragma once
#include <Windows.h>

class Map
{
private:
	static const int  VERTICAL_SIZE = 13, HORIZONTAL_SIZE = 49;
	char map[VERTICAL_SIZE][HORIZONTAL_SIZE];

public:
	Map(void);
	~Map(void);

	void initializeMap(int humanShips[10][10]);
	void updateMap(int humanShips[10][10], int humanHits[10][10], int computerShips[10][10], int computerHits[10][10]);
	void showEndMap(int humanShips[10][10], int humanHits[10][10], int computerShips[10][10], int computerHits[10][10]);
};