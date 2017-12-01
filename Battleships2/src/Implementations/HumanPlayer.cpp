/*
 * HumanPlayer.cpp
 *
 *  Created on: Oct 27, 2017
 *      Author: HZinovatna
 */

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() {

}

HumanPlayer::~HumanPlayer() {
}

void HumanPlayer::initialize(int fieldSize) {

	FIELD_SIZE = fieldSize;
	  std::vector<int> row(FIELD_SIZE, 0);
	  std::vector<std::vector<int> > field(FIELD_SIZE, row);
	  std::vector<std::vector<int> > shots(FIELD_SIZE, row);

	  this->field = field;
	  this->shots = shots;

	  setShips();
}

void HumanPlayer::setShips() {
	setShip(4);
	setShip(3);
	setShip(3);
	setShip(2);
	setShip(2);
	setShip(2);
	setShip(1);
	setShip(1);
	setShip(1);
	setShip(1);
}


void HumanPlayer::setShip(int size){
	int x = 0, y = 0;
	bool isHorizontal = false;
	bool place = false;

	while (place == false) {
	  x = rand() % FIELD_SIZE;
	  y = rand() % FIELD_SIZE;

	  int horizontal = rand() % 2;

	  if (horizontal == 0)
	    isHorizontal = true;

	  place = checkPlaceForShip(x, y, size, isHorizontal);
	}

	if (isHorizontal) {
	  for (int i = y; i < y + size; i++)
		  field[x][i] = 1;
	}
	else {
	  for (int i = x; i < x + size; i++)
		  field[i][y] = 1;
	}
}

bool HumanPlayer::checkPlaceForShip(int x, int y, int size, bool isHorizontal) {
	if(isHorizontal) {
		if (field[x][y] == 1)
		    return false;

		  //check if the ship fits
		  if (y > FIELD_SIZE - size)
		    return false;

		  for (int i = y + 1; i < y + size; i++) {
		    if (field[x][i] == 1)
		      return false;
		  }

		  //check if cells around the ship are empty
		  for (int i = x - 1; i < x + 2; i++) {
		    for (int j = y - 1; j < y + size + 1; j++) {
		      try {
		        if (field.at(i).at(j) == 1)
		          return false;
		      }
		      catch (const std::out_of_range& e) {
		        continue;
		      }
		    }
		  }

		  return true;
	}
	else {
		if (field[x][y] == 1)
		    return false;
		  if (x > FIELD_SIZE - size)
		    return false;

		  //check if the ship fits
		  for (int i = x + 1; i < x + size; i++) {
		    if (field[i][y] == 1)
		      return false;
		  }

		  //check if cells around the ship are empty
		  for (int i = x - 1; i < x + size + 1; i++) {
		    for (int j = y - 1; j < y + 2; j++) {
		      try {
		        if (field.at(i).at(j) == 1)
		          return false;
		      }
		      catch (const std::out_of_range& e) {
		        continue;
		      }
		    }
		  }
		  return true;
	}
}

std::vector<std::vector<int> > HumanPlayer::getShips(){
	return field;
}
