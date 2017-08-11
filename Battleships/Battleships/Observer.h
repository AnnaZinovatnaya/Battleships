#pragma once

#include "Observer.h"


class Observer
{
public:
	Observer();
	~Observer();

	void virtual update() = 0;
};

