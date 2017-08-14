#ifndef Player_h__
#define Player_h__

#include <cstdlib>
#include <ctime>
#include<iostream>
#include <list>
#include <vector>

#include "Ship.h"
#include "HorizontalShip.h"
#include "VerticalShip.h"

using namespace std;

class Player
{
  public:
    Player();
    ~Player();

    void initialize();

    vector<vector<int> > getShips() const;
    vector<vector<int> > getHits() const;

    list<Ship> getFleet() const;

    void hit(vector<int> hit);

    bool isAnyShipHit(int x, int y) const;

    bool markSunkShips(vector<vector<int> > enemyHits);

    bool checkDefeat() const;

    int  countSunkShips() const;
  protected:
    vector<vector<int> > hits;
  private:
    vector<vector<int> > ships;
    list<Ship> fleet;

    Ship setShip(int size);
};

#endif