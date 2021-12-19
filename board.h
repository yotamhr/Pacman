#pragma once
#include "defenitions.h"
#include "point.h"

class Board
{
private:
	char board[ROWS][COLS];
	int numOfCols;
	int numOfRows;
	point legend;
	int breadCrumbsInBoard;
	int ghostCounter;
	int score;
	int food;

public:
	Board();
	char getPos(int x, int y)const;
	void setPos(int x, int y, char c);
	void setNumOfCols(int num);
	void SetNumOfRows(int num);
	int getNumOfCols()const;
	int getNumOfRows()const; 
	void setLegend(int x, int y);
	int getlegendX()const;
	int getlegendY()const;
	int  getBreadCrumbs()const;
	void setBreadCrumbs(int num);
	int  getScore()const;
	void setScore(int num);
	int  getGhostCount()const;
	void setGhostCount(int num);
	int getFood()const;
	void addFood();
	void setFood(int _x);
};

