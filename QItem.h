#pragma once
//this class is part of BFS algorithm
class QItem
{

public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w) {}
};

