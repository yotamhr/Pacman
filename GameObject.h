#pragma once
#include "point.h"
#include "defenitions.h"
#include "board.h"
class GameObject
{
protected:
	point p{};
	Board *_board = nullptr;
	point firstP{};
	
public:
	void setpX(int x);
	void setpY(int y);
	int  getpX() const;
	int  getpY() const;
	void setBoard(Board* board);
	int getFirstPx() const;
	int getFirstPy() const;
	void setFirstP(int x,int y);
	void doActualMovement(int x, int y, int i, int j,char c);
	
	
};

