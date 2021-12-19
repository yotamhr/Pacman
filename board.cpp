#include "board.h"
#include "QItem.h"
using namespace std; 

Board::Board()
{
	 legend.setX(0);
	 legend.setY(0);
	 numOfCols = 0;
	 numOfRows = 0;
	 breadCrumbsInBoard = 0;
	 ghostCounter = 0;
	 score = 0;
	 food = 0;
}

void Board::setPos(int x, int y, char c)
{
	board[x][y] = c;
}

void Board::setNumOfCols(int num)
{
	numOfCols = num;
}

void Board::SetNumOfRows(int num)
{
	numOfRows = num;
}

int Board::getNumOfCols()const
{
	return numOfCols;
} 

int Board::getNumOfRows()const
{
	return numOfRows;
} 

char Board:: getPos(int x, int y)const 
{
	return board[x][y];
}

void Board::setLegend(int x, int y)
{
	legend.setX(x);
	legend.setY(y);
}

int Board:: getlegendX()const
{
	return legend.getX();
}

int Board:: getlegendY()const
{
	return legend.getY();
}

int Board::getBreadCrumbs()const
{
	return breadCrumbsInBoard;
}

void  Board::setBreadCrumbs(int num)
{
	breadCrumbsInBoard = num;
}

int Board::getScore()const
{
	return score;
}

void  Board::setScore(int num)
{
	score = num;
}

int Board::getGhostCount()const
{
	return ghostCounter;
}

void  Board::setGhostCount(int num)
{
	ghostCounter = num;
}

int Board::getFood()const
{
	return food;
}

void Board::addFood()
{
	food++;
}

void Board::setFood(int _x)
{
	food = _x;
}
