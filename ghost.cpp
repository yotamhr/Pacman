#include "ghost.h"
#include <queue>


int Ghost::minDistance(int x , int y)
{
	QItem source(0, 0, 0);

	// To keep track of visited QItems. Marking
	// blocked cells as visited.
	int rows = _board->getNumOfRows();
	int cols = _board->getNumOfCols();
	bool** visited = new bool* [rows];
	for (int i = 0; i < rows; i++)
	{
		visited[i] = new bool[cols];
	}

	// initializing source location
	source.row = y;
	source.col = x;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j <cols; j++)
		{
			if (_board->getPos(i,j) == '#'|| _board->getPos(i, j) == '^')
				visited[i][j] = true;
			else
				visited[i][j] = false;	
		}
	}

	// applying BFS on matrix cells starting from source
	queue<QItem> q;
	q.push(source);
	visited[source.row][source.col] = true;
	while (!q.empty()) {
		QItem p = q.front();
		q.pop();

		// Destination found;
		if (_board->getPos(p.row, p.col) == '@')
		{
			for (int i = 0; i < rows; i++)
			{
				delete visited[i];
			}
			delete[] visited;
			return p.dist;
		}

		// moving up
		if (p.row - 1 > 0 &&
			visited[p.row - 1][p.col] == false) {
			q.push(QItem(p.row - 1, p.col, p.dist + 1));
			visited[p.row - 1][p.col] = true;
		}

		// moving down
		if (p.row + 1 < rows-1 &&
			visited[p.row + 1][p.col] == false) {
			q.push(QItem(p.row + 1, p.col, p.dist + 1));
			visited[p.row + 1][p.col] = true;
		}

		// moving left
		if (p.col - 1 > 0 &&
			visited[p.row][p.col - 1] == false) {
			q.push(QItem(p.row, p.col - 1, p.dist + 1));
			visited[p.row][p.col - 1] = true;
		}

		// moving right
		if (p.col + 1 < cols-1 &&
			visited[p.row][p.col + 1] == false) {
			q.push(QItem(p.row, p.col + 1, p.dist + 1));
			visited[p.row][p.col + 1] = true;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete visited[i];
	}
	delete[] visited;
	return -1;
}




