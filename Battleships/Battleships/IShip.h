#ifndef IShip_h__
#define IShip_h__

#include <vector>
using namespace std;

#include "GameRules.h"

#include <iostream>
using namespace std;

class IShip
{
  public:
    int x;
    int y;
    int size;

    IShip(int x, int y, int size);
    IShip::IShip();
    ~IShip();

    virtual bool checkPlace(vector<vector<int> > ships) = 0;
    virtual int findFirstX(int lastHitX, int lastHitY, vector<vector<char> > cleverHits) = 0;
    virtual int findFirstY(int lastHitX, int lastHitY, vector<vector<char> > cleverHits) = 0;
    virtual int findSize(int firstX, int firstY, vector<vector<char> > cleverHits) = 0;
};

#endif
