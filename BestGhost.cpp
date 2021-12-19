#include "BestGhost.h"

void BestGhost::ghostMove()
{
	int x = p.getX();
	int y = p.getY();
	int mDist = minDistance(x, y);
	int i, j;
	//Up
	if ((minDistance(x, y - 1) < mDist) && (_board->getPos(y-1,x)!='#') && (_board->getPos(y - 1, x) != '^'))
	{
		i = 0; j = -1;
		doActualMovement(x, y , i , j ,'$');
	}
	//down
	else if ((minDistance(x, y + 1) < mDist) && (_board->getPos(y + 1, x) != '#') && (_board->getPos(y + 1, x) != '^'))
	{
		i = 0; j =1;
		doActualMovement(x, y, i, j, '$');
	}
	//Right
	else if ((minDistance(x+1, y) < mDist) && (_board->getPos(y, x+1) != '#') && (_board->getPos(y, x+1) != '^'))
	{
		i = 1; j = 0;
		doActualMovement(x, y, i, j, '$');
	}
	//Left
	else if ((minDistance(x-1, y) < mDist) && (_board->getPos(y, x-1) != '#') && (_board->getPos(y, x-1) != '^'))
	{
		i =-1; j = 0;
		doActualMovement(x, y, i, j, '$');
	}

}


