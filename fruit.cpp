#include "fruit.h"

void Fruit::fruitMove(int fruitCounter)
{
	int x, y,i=0,j=0;
	char val;
		
	if (fruitCounter == 0) 
	{
		y = (rand() % (_board->getNumOfRows()-1))+1;
		x = (rand() % (_board->getNumOfCols()-1)) + 1;
		value = (rand() % 5) + 5;
		
		
		while (_board->getPos(y, x) != ' ' && _board->getPos(y, x) != '*')
		{
			y = (rand() % (_board->getNumOfRows() - 1)) + 1;
			x = (rand() % (_board->getNumOfCols() - 1)) + 1;
		}

			gotoxy(x, y);
			cout << value; 
			p.setX(x);
			p.setY(y);
	}
	val = '0'+value;
	if(fruitCounter!=0) 
	{
		int x = p.getX();
		int y = p.getY();
		int random = rand() % 4;
		if (fruitCounter == 20) {
			gotoxy(x, y);
			cout << _board->getPos(y, x);
			p.setX(0);
			p.setY(0);
		}
		else {
			switch (random)
			{
			case UP:
				if (_board->getPos(y - 1, x) == '#')
				{
					break;
				}
				else if (_board->getPos(y - 1, x) == '^')
				{
					break;
				}
				else if (_board->getPos(y - 1, x) == '*'|| _board->getPos(y - 1, x) == ' ')
				{
					j = -1;
					doActualMovement(x, y, i, j, val);
				}
				break;
			case DOWN:
				if (_board->getPos(y + 1, x) == '#')
					break;
			
				else if (_board->getPos(y + 1, x) == '^')
					break;
				
				else if (_board->getPos(y + 1, x) == '*' || _board->getPos(y + 1, x) == ' ')
				{
					j = 1;
					doActualMovement(x, y, i, j, val);
				}
					break;
				

			case LEFT:
				if (_board->getPos(y, x - 1) == '#')
					break;
				
				else if (_board->getPos(y, x - 1) == '^')
					break;
				
				else if (_board->getPos(y, x - 1) == '*'|| _board->getPos(y, x - 1) == ' ')
				{
					i = -1;
					doActualMovement(x, y, i, j, val);
				}
				break;
			case RIGHT:
				if (_board->getPos(y, x + 1) == '#')
					break;
				
				else if (_board->getPos(y, x + 1) == '^')
					break;
				
				else if (_board->getPos(y, x + 1) == '*'|| _board->getPos(y, x + 1) == ' ')
				{
					i = 1;
					doActualMovement(x, y, i, j, val);
				}
				break;
			}
		}
	}
}

int Fruit::getValue()const
{
	return value;
}

void Fruit::setValue(int val)
{
	value = val;
}

