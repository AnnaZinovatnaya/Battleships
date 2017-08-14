#ifndef HorizontalShip_h__
#define HorizontalShip_h__

#include "IShip.h"

class HorizontalShip: public IShip
{
  public:
    HorizontalShip(int x, int y, int size);
    HorizontalShip::HorizontalShip();
    ~HorizontalShip();

    bool checkPlace(vector<vector<int> > ships);

    int findFirstX(int lastHitX, int lastHitY, vector<vector<char> > cleverHits);
    int findFirstY(int lastHitX, int lastHitY, vector<vector<char> > cleverHits);
    int findSize(int firstX, int firstY, vector<vector<char> > cleverHits);
};

#endif
