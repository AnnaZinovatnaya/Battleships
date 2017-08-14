#ifndef Observer_h__
#define Observer_h__

#include "Observer.h"

class Observer
{
  public:
    Observer();
    ~Observer();

    void virtual update() = 0;
};

#endif