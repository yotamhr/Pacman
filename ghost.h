#pragma once
#include "GameObject.h"
#include "defenitions.h"
#include "QItem.h"

class Ghost : public GameObject
{
public:
	Ghost(){};

	virtual void ghostMove()=0;
	int minDistance(int x, int y);
};

