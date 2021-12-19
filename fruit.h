#pragma once
#include "GameObject.h"
#include "defenitions.h"


class Fruit :public GameObject
{
private:
	int value=0;


public:
	void fruitMove(int fruitCounter); 
	int getValue()const;
	void setValue(int val);

};

