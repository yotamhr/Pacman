#pragma once
#include "pacman.h"
#include "ghost.h"
#include "board.h"
#include "GameObject.h"
#include "fruit.h"
#include "BestGhost.h"
#include "NoviceGhost.h"


class Game
{
private:
	Board board;
	Pacman pacman;
	vector<Ghost*> ghostArr;
	vector<string> fileNames;
	Fruit fruit; 
	int num_of_curr_board = 0;

public:
	Game(){}
	Game& operator=(const Game& other) = delete;
	Game(const Game& other) = delete;
	void play(int level);
	void lostLife();
	void menu();
	void lose();
	void win();
	void reset();
	void checkIntersections(char* c , int* fruitRest);
	int readFile(string fileName,int ghostLevel);
	void buildBoard(int rows, int cols, ifstream* file, int ghostLevel);
	void getFiles();
	int getNumOfCurrBoard()const;
	void setNumOfCurrBoard(int num);
	void wonTheGame();
	void instructions()const;
	int ghostMenu()const;
	void changeArrOfGhost(vector<Ghost*>&ghostArr,int ghostSwitcher);
	~Game();
	
};

