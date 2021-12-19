#include "GameObject.h"

int GameObject::getpX() const
{
	return p.getX() ;
}

int GameObject::getpY() const
{
	return p.getY();
}

void GameObject::setpX(int x)
{
	p.setX(x);
}

void GameObject::setpY(int y)
{
	p.setY(y);
}

void GameObject::setBoard(Board* board) {
	_board = board;
}

int GameObject::getFirstPx() const
{
	return firstP.getX();
}

int GameObject::getFirstPy() const
{
	return firstP.getY();
}

void GameObject::setFirstP(int x, int y)
{
	firstP.setX(x);
	firstP.setY(y);
}

void GameObject::doActualMovement(int x, int y, int i, int j, char c) //general func that moves all the creature
{
	c = (char)c;
	gotoxy(x + i, y + j);
	cout << c;
	gotoxy(x, y);
	if (c == '$'||(c>='5'&&c<='9'))
	{
		if (_board->getPos(y, x) == '$')
		{
			_board->setPos(y, x, '*');
			cout << '*';
		}
		
		else
			cout << _board->getPos(y, x);
	}
	if (c == '@')
	{
		cout << " ";
		_board->setPos(y, x, ' ');
	
		if (_board->getPos(y + j, x + i) == '*') //checks if pacman step on food 
		{
		_board->addFood();
		_board->setScore(_board->getScore() + 1);
		gotoxy(_board->getlegendX(), _board->getlegendY());
		cout << "Score:" << _board->getScore();
		}	
	}
	p.setX(x + i);
	p.setY(y + j);
}


