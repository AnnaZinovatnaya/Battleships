#ifndef VerticalShip_h__
#define VerticalShip_h__
#include "IShip.h"

class VerticalShip: public IShip
{
  public:
    VerticalShip(int x, int y, int size);
    VerticalShip();
    ~VerticalShip();

    bool checkPlace(vector<vector<int> > ships) const;

    int findFirstX(int lastHitX, int lastHitY, vector<vector<char> > cleverHits) const;
    int findFirstY(int lastHitX, int lastHitY, vector<vector<char> > cleverHits) const;
    int findSize(int firstX, int firstY, vector<vector<char> > cleverHits) const;
    void markAround(Ship const & sunkShip, vector<vector<char> > & cleverHits);
};
#endif