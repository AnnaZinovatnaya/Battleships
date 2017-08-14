#ifndef VerticalShip_h__
#define VerticalShip_h__
#include "IShip.h"

class VerticalShip: public IShip
{
  public:
    VerticalShip(int x, int y, int size);
    VerticalShip();
    ~VerticalShip();

    bool checkPlace(vector<vector<int> > ships);

    int findFirstX(int lastHitX, int lastHitY, vector<vector<char> > cleverHits);
    int findFirstY(int lastHitX, int lastHitY, vector<vector<char> > cleverHits);
    int findSize(int firstX, int firstY, vector<vector<char> > cleverHits);
};
#endif