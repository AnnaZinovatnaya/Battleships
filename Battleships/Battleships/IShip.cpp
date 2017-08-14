#include "IShip.h"



IShip::IShip(int x, int y, int size)
{
  this->x = x;
  this->y = y;
  this->size = size;
}

IShip::IShip()
{
  this->x = 0;
  this->y = 0;
  this->size = 0;
}

IShip::~IShip()
{
}


