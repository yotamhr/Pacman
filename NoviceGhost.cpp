#include "NoviceGhost.h"

void NoviceGhost::ghostMove()
{
	int i = 0, j = 0;
	int x = p.getX();
	int y = p.getY();
	int random = rand() % 4;
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
			doActualMovement(x, y, i, j, '$');
		}
		break;
	case DOWN:

		if (_board->getPos(y + 1, x) == '#')
		{
			break;
		}
		else if (_board->getPos(y + 1, x) == '^')
		{
			break;
		}
		else if (_board->getPos(y + 1, x) == '*'|| _board->getPos(y + 1, x) == ' ')
		{
			j = 1;
			doActualMovement(x, y, i, j, '$');
		}
		break;

	case LEFT:
		if (_board->getPos(y, x - 1) == '#')
		{
			break;
		}
		else if (_board->getPos(y, x - 1) == '^')
		{
			break;
		}
		else if (_board->getPos(y, x - 1) == '*'|| _board->getPos(y, x - 1) == ' ')
		{
			i = -1;
			doActualMovement(x, y, i, j, '$');
		}
		break;
	case RIGHT:
		if (_board->getPos(y, x + 1) == '#')
		{
			break;
		}
		else if (_board->getPos(y, x + 1) == '^')
		{
			break;
		}
		else if (_board->getPos(y, x + 1) == '*'|| _board->getPos(y, x + 1) == ' ')
		{
			i = 1;
			doActualMovement(x, y, i, j, '$');
		}
		break;
	}
}

