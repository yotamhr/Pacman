#include "pacman.h"

Pacman::Pacman()
{
	life = 3; 
}

void Pacman::subLife()
{
	life--;
} 

int Pacman::getLife()const
{
	return life;
}

void Pacman::setLife(int _x)
{
	life = _x;
}

void Pacman::pacmanMove(char* c, char* prevDirec,int cols,int rows) 
//checks what is the next step of the pacman according to the direction  that entered and moves the pacman 
{       
	int i, j;
	int foodCounter = 0;

	int x = p.getX();
	int y = p.getY();

	char temp = *c;

	Sleep(200);
	if (_kbhit())
		*c = _getch();
	if (*c != ESC && *c != BIGLEFT && *c != BIGRIGHT && *c != BIGUP && *c != BIGDOWN && *c != SMALLLEFT && *c != SMALLRIGHT && *c != SMALLUP && *c != SMALLDOWN && *c != SMALLSTAY && *c != BIGSTAY)
		*c = temp;
	
	//RIGHT Movement
	if (*c == BIGRIGHT || *c == SMALLRIGHT)
	{
		if (_board->getPos(y, x + 1) == '#')
		{
			*c = SMALLSTAY;
		}
		else if (_board->getPos(y, x + 1) == '^')
		{
			gotoxy(x, y);
			cout << ' ';
			_board->setPos(y, x, ' ');
			x = 1;
			gotoxy(x, y);
			cout << '@';
			p.setX(x);
		}
		else {
			i = 1; j = 0;
			doActualMovement(x, y, i, j, '@');
		}
		*prevDirec = *c;
	}
	//DOWN Movement
	else if (*c == BIGDOWN || *c == SMALLDOWN)
	{
		if (_board->getPos(y + 1, x) == '#')
		{
			*c = SMALLSTAY;
		}
		else if (_board->getPos(y + 1, x) == '^')
		{
			gotoxy(x, y);
			cout << ' ';
			_board->setPos(y, x, ' ');
			y = 1;
			gotoxy(x, y);
			cout << '@';
			p.setY(y);
		}
		else {
			i = 0; j = 1;
			doActualMovement(x, y, i, j, '@');
		}
		*prevDirec = *c;

	}
	//Left Movement
	else if (*c == BIGLEFT || *c == SMALLLEFT)
	{
		if (_board->getPos(y, x - 1) == '#')
		{
			*c = SMALLSTAY;
		}
		else if (_board->getPos(y, x - 1) == '^')
		{
			gotoxy(x, y);
			cout << ' ';
			_board->setPos(y, x, ' ');
			x = cols - 2;
			gotoxy(x, y);
			cout << '@';
			p.setX(x);
		}
		else {
			i = -1; j = 0;
			doActualMovement(x, y, i, j, '@');
		}
		*prevDirec = *c;

	}
	//Up Movement
	else if (*c == BIGUP || *c == SMALLUP)
	{
		if (_board->getPos(y - 1, x) == '#')
		{
			*c = SMALLSTAY;
		}
		else if (_board->getPos(y - 1, x) == '^')
		{
			gotoxy(x, y);
			cout << ' ';
			_board->setPos(y, x, ' ');
			y = rows - 2;
			gotoxy(x, y);
			cout << '@';
			p.setY(y);
			

		}
		else {
			i = 0; j = -1;
			doActualMovement(x, y, i, j, '@');
		}
		*prevDirec = *c;
	}
	
	_board->setPos(p.getY(), p.getX(),'@');

	if (*c == BIGSTAY || *c == SMALLSTAY)
	{
		gotoxy(x, y);
		cout << "@";
		*prevDirec = *c;
	}
	if (*c == ESC) //pauses the game 
	{
		while (!_kbhit() || _getch() != ESC) {}
		*c = *prevDirec;
	}
}