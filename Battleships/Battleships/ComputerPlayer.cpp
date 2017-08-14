#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer()
{
  vector<char> row(FIELD_SIZE, '1');
  vector<vector<char> > cleverHits(FIELD_SIZE, row);

  this->cleverHits = cleverHits;

  lastHitX = 0;
  lastHitY = 0;
}



ComputerPlayer::~ComputerPlayer()
{
}



void ComputerPlayer::hit()
{
  bool lastHitSuccessful = false;
  if (cleverHits[lastHitX][lastHitY] == 'X')
    lastHitSuccessful = true;

  //if computer hit any user's ship, it hits around that cell (not randomly)
  int x = 0, y = 0;
  if (lastHitSuccessful) {

    direction direction = chooseSideToHit();
    if (direction == TOP) {
      x = lastHitX - 1; 
      y = lastHitY; 
    }
    else if (direction == BOTTOM) {
      x = lastHitX + 1;
      y = lastHitY;
    }
    else if (direction == LEFT) {
      x = lastHitX;
      y = lastHitY - 1;
    }
    else if (direction == RIGHT) {
      x = lastHitX;
      y = lastHitY + 1;
    }
  }
  else {
    bool suitableHit = false;
    while (suitableHit == false) {
      x = rand() % FIELD_SIZE;
      y = rand() % FIELD_SIZE;

      if (cleverHits[x][y] != '0' && cleverHits[x][y] != 'X')
        suitableHit = true;
    }
  }

  hits[x][y] = 1;

  lastHitX = x;
  lastHitY = y;
}



void ComputerPlayer::markMissedHit() 
{
  cleverHits[lastHitX][lastHitY] = '0';
}



void ComputerPlayer::markSuccessHit()
{
  cleverHits[lastHitX][lastHitY] = 'X';
}



void ComputerPlayer::markSunkShip()
{
  bool isHorizontal = isShipHorizontal();
  IShip* iShip;
  if (isHorizontal)
    iShip = new HorizontalShip;
  else
    iShip = new VerticalShip;

  int firstX = iShip->findFirstX(lastHitX, lastHitY, cleverHits);
  int firstY = iShip->findFirstY(lastHitX, lastHitY, cleverHits);

  int size = iShip->findSize(firstX, firstY, cleverHits);

  Ship foundShip(firstX, firstY, size, isHorizontal);

  iShip->markAround(foundShip, cleverHits);
}



bool ComputerPlayer::isShipHorizontal() const
{
  bool isLastHitNearLeftBorder = false;
  if (lastHitY == 0)
    isLastHitNearLeftBorder = true;

  if (isLastHitNearLeftBorder) {
    if (cleverHits[lastHitX][lastHitY + 1] == 'X')
      return true;
  }

  bool isLastHitInCenter = false;
  if (lastHitY > 0 && lastHitY < FIELD_SIZE - 1)
    isLastHitInCenter = true;

  if (isLastHitInCenter) {
    if (cleverHits[lastHitX][lastHitY - 1] == 'X')
      return true;
    if (cleverHits[lastHitX][lastHitY + 1] == 'X')
      return true;
  }

  bool isLastHitNearRightBorder = false;
  if (lastHitY == FIELD_SIZE - 1)
    isLastHitNearRightBorder = true;

  if (isLastHitNearRightBorder) {
    if (cleverHits[lastHitX][lastHitY - 1] == 'X')
      return true;
  }

  return false;
}



direction ComputerPlayer::chooseSideToHit() const
{
  if (lastHitX > 0 && cleverHits[lastHitX - 1][lastHitY] == '1')
    return TOP;

  if (lastHitX < FIELD_SIZE - 1 && cleverHits[lastHitX + 1][lastHitY] == '1')
    return BOTTOM;

  if (lastHitY > 0 && cleverHits[lastHitX][lastHitY - 1] == '1')
    return LEFT;

  if (lastHitY < FIELD_SIZE - 1 && cleverHits[lastHitX][lastHitY + 1] == '1')
    return RIGHT;
}