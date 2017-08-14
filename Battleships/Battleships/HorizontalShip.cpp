#include "HorizontalShip.h"

HorizontalShip::HorizontalShip(int x, int y, int size): IShip(x, y, size)
{
}


HorizontalShip::HorizontalShip()
{
}



HorizontalShip::~HorizontalShip()
{
}



bool HorizontalShip::checkPlace(vector<vector<int>> ships)
{
  if (ships[x][y] == 1)
    return false;

  //check if the ship fits
  if (y > FIELD_SIZE - size)
    return false;

  for (int i = y + 1; i < y + size; i++) {
    if (ships[x][i] == 1)
      return false;
  }


  //check if cells around the ship are empty
  for (int i = x - 1; i < x + 2; i++) {
    for (int j = y - 1; j < y + size + 1; j++) {
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

int HorizontalShip::findFirstX(int lastHitX, int lastHitY, vector<vector<char>> cleverHits)
{
  return lastHitX;
}

int HorizontalShip::findFirstY(int lastHitX, int lastHitY, vector<vector<char>> cleverHits)
{
  bool isLastHitNearRightBorder = false;
  if (lastHitY == 0)
    isLastHitNearRightBorder = true;

  if (isLastHitNearRightBorder) {
    return lastHitY;
  }
  else {
    int currentY = lastHitY;

    bool cellBelongsToShip = true;
    while (cellBelongsToShip) {
      try {
        if (cleverHits.at(lastHitX).at(currentY) == 'X')
          currentY--;
        else
          cellBelongsToShip = false;
      }
      catch (const std::out_of_range& e) {
        cellBelongsToShip = false;
      }
    }

    return currentY + 1;
  }
}

int HorizontalShip::findSize(int firstX, int firstY, vector<vector<char>> cleverHits)
{
  int size = 1;
  int currentY = firstY + 1;

  while (currentY <= FIELD_SIZE - 1) {
    try {
      if (cleverHits[firstX][currentY] == 'X') {
        currentY++;
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
