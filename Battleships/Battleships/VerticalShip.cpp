#include "VerticalShip.h"



VerticalShip::VerticalShip(int x, int y, int size): IShip(x, y, size)
{
}



VerticalShip::VerticalShip()
{
}



VerticalShip::~VerticalShip()
{
}



bool VerticalShip::checkPlace(vector<vector<int>> ships)
{
  if (ships[x][y] == 1)
      return false;
  if (x > FIELD_SIZE - size)
    return false;

  //check if the ship fits
  for (int i = x + 1; i < x + size; i++) {
    if (ships[i][y] == 1)
      return false;
  }

  //check if cells around the ship are empty
  for (int i = x - 1; i < x + size + 1; i++) {
    for (int j = y - 1; j < y + 2; j++) {
      try {
        if (ships.at(i).at(j) == 1)
          return false;
      }
      catch (const std::out_of_range& e) {
        continue;
      }
    }
  }

  return true;
}

int VerticalShip::findFirstX(int lastHitX, int lastHitY, vector<vector<char>> cleverHits)
{
  bool isLastHitNearTopBorder = false;
  if (lastHitX == 0)
    isLastHitNearTopBorder = true;

  if (isLastHitNearTopBorder) {
    return lastHitX;
  }
  else {
    int currentX = lastHitX;

    bool cellBelongsToShip = true;
    while (cellBelongsToShip) {
      try {
        if (cleverHits[currentX][lastHitY] == 'X')
          currentX--;
        else
          cellBelongsToShip = false;
      }
      catch (const std::out_of_range& e) {
        cellBelongsToShip = false;
      }
    }

    return currentX + 1;
  }
}

int VerticalShip::findFirstY(int lastHitX, int lastHitY, vector<vector<char>> cleverHits)
{
  return lastHitY;
}

int VerticalShip::findSize(int firstX, int firstY, vector<vector<char>> cleverHits)
{
  int size = 1;
  int currentX = firstX + 1;

  while (currentX <= FIELD_SIZE - 1) {
    try {
      if (cleverHits.at(currentX).at(firstY) == 'X') {
        currentX++;
        size++;
      }
      else {
        break;
      }
    }
    catch (const std::out_of_range& e) {
      break;
    }
  }
  return size;
}
