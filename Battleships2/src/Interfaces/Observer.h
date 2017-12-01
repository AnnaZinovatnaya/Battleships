#ifndef Observer_h__
#define Observer_h__

class Observer
{
  public:
    Observer();
    virtual ~Observer();
    void virtual update() = 0;
};

#endif