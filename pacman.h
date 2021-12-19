#pragma once
#include "defenitions.h"
#include "GameObject.h"

class Pacman : public GameObject
{
private:
	
	int life;
public:
	Pacman();
	void subLife();
	int getLife()const;
	void setLife(int _x);
	void pacmanMove(char* c, char* prevDirec,int cols, int rows);

};

