#include "game.h"

void Game::play(int ghostLevel) //running the game
{
	int fruitRest=0, countGhostMoves=0;
	int ghostSwitcher = 1;
	Ghost* ghost = nullptr;
	int flag = 1;
	char c = 'k';
	char prevDirec = 'k';
	int size = board.getGhostCount();

	for (int i = 0; i < size; i++)
		ghostArr[i]->setBoard(&board);

	pacman.setBoard(&board);
	fruit.setBoard(&board);

	while (pacman.getLife() != 0 && board.getFood() != board.getBreadCrumbs())
	{
		pacman.pacmanMove(&c, &prevDirec,board.getNumOfCols(), board.getNumOfRows());

		if (flag == 1)//ghost and fruit move only once every two moves of the pacman
		{
			if (c != 'k')
			{
				if (fruitRest <= 20) { //fruit appears and disappears every 20 moves
					fruit.fruitMove(fruitRest);
				}
				for (int i = 0; i < ghostArr.size(); i++)
					ghostArr[i]->ghostMove();

				fruitRest++;
				countGhostMoves++;
				if (ghostLevel == '2' && countGhostMoves == 20)//ghost changes moving algorithem every 20 moves
				{
					changeArrOfGhost(ghostArr, ghostSwitcher);
					ghostSwitcher *= -1;
					countGhostMoves = 0;
				}
					
			}
		}
		flag *= -1;

		if (fruitRest == 40)
			fruitRest = 0;
		checkIntersections(&c, &fruitRest);

		if (board.getFood() == board.getBreadCrumbs())
		{
			win();
		}
	}
	board.setFood(0);
}

void Game::lostLife() //when lost a life, reset all the creatures to the starting loaction, and checks if you lost all your lifes
{
	for (int i = 0; i < ghostArr.size(); i++)
	{
		gotoxy((*ghostArr[i]).getpX(), (*ghostArr[i]).getpY());
		if (board.getPos((*ghostArr[i]).getpY(), (*ghostArr[i]).getpX()) == '*')
		{
			cout << '*';
		}
		else {
			cout << ' ';
		}
	}
	pacman.subLife();
	gotoxy(board.getlegendX(), board.getlegendY()+1);
	cout << "life:" << pacman.getLife();
	if (pacman.getLife() == 0)
	{
		lose();
		return;
	}
	board.setPos(pacman.getpY(), pacman.getpX(), ' ');
	pacman.setpX(pacman.getFirstPx());
	pacman.setpY(pacman.getFirstPy());
	board.setPos(pacman.getpY(), pacman.getpX(), '@');

	gotoxy(pacman.getFirstPx(), pacman.getFirstPy());
	cout << "@";
	for (int i = 0; i < ghostArr.size(); i++)
	{
		ghostArr[i]->setpX(ghostArr[i]->getFirstPx());
		ghostArr[i]->setpY(ghostArr[i]->getFirstPy());
		gotoxy(ghostArr[i]->getFirstPx(), ghostArr[i]->getFirstPy());
		cout << "$";
	}
}

void Game::menu()
{
	int i = 0, level,fileopened;
	string str;
	getFiles();
	bool flag = true;
	while (true && flag)
	{
		int choice;
		cout << "(1) Start a new game"<< endl << endl;
		cout << "(2) Choose specific file to play" << endl << endl;
		cout << "(8) Present instructions and keys"<< endl << endl;
		cout << "(9) Exit";

		while (!_kbhit()) {}

		choice = _getch();
		while (choice != '1' && choice != '8' && choice != '9' && choice != '2')
		{
			if (_kbhit())
				choice = _getch();
		}
		switch (choice)
		{
		case '1':
			 level = ghostMenu(); 
			while (i < fileNames.size() && pacman.getLife()!=0)
			{
				system("CLS");
				readFile(fileNames[num_of_curr_board],level);
				play(level);
				i++;
			}
			if (pacman.getLife() == 0)
			{
				i = 0;
				pacman.setLife(3);
			}
			else if (fileNames.size() == 0)
			{
				cout << "There are no matching boards to play on" << endl;
				Sleep(2000);
				return;
			}
			else
			{
				wonTheGame();
				i = 0;
			}
				
			break;

		case '2':
			level = ghostMenu();
			system("CLS");
			cout << "Please enter file's name:" << endl;
			getline(cin,str);
			system("CLS");
			fileopened=readFile(str,level);
			if (fileopened)
			{
				play(level);
				if (pacman.getLife() > 0)
					wonTheGame();
				
			}
			break;

		case '8':
			instructions();
			break;
		case '9':
			flag = false;
			break;
			
		}
	}
}

void Game::lose()//lost all life
{
	system("CLS");
	cout << "GAME OVER\n";
	cout << "Press any key to return to menu...";
	reset();
	while (!_kbhit()) {}
	system("CLS");
}

void Game::win()//won the curr screen
{
	system("CLS");
	cout << "CONGRATULATIONS!!! YOU HAVE WON THE CURRENT BOARD!" << endl;
	cout << "PRESS ANY KEY TO MOVE TO THE NEXT BOARD";
	while (!_kbhit()) {}
	int dummy=_getch();
	num_of_curr_board++;
	ghostArr.clear();
	board.setGhostCount(0);
	system("CLS");
}

void Game::reset() 
{
	board.setFood(0);
	board.setScore(0);
	num_of_curr_board = 0;
	board.setGhostCount(0);
	for (int i = 0; i < ghostArr.size(); i++)
		delete ghostArr[i];
	ghostArr.clear();

}

void Game::checkIntersections(char* c , int* fruitRest)
{
	for (auto i : ghostArr)
	{
		if (pacman.getpX() == (*i).getpX() && pacman.getpY() == (*i).getpY())//checks if pacman meets a ghost
		{
			lostLife();
			*c = 'k';
		}
	}
	
	if (pacman.getpX() == fruit.getpX() && pacman.getpY() == fruit.getpY())//check pacman meets a fruit
	{
		int score = board.getScore();
		score += fruit.getValue();
		board.setScore(score);
		*fruitRest = 20; 
	}
	for (auto i : ghostArr)
	{
		if (fruit.getpX() == (*i).getpX() && fruit.getpY() == (*i).getpY())//checks if fruit meets a ghost
			*fruitRest = 20;
	}
}

int Game::readFile(string fileName, int ghostLevel)
{
	int numOflines=1, numOfCol; 
	ifstream file;
	string str;
	file.open(fileName);

	if (file.fail())
	{
		cout << "error in opening file";
		Sleep(2000);
		system("CLS");
		return 0;
	}
	
	getline(file, str);
	numOfCol = str.size();

	while (getline(file, str))
		numOflines++;
	
	board.setNumOfCols(numOfCol);
	board.SetNumOfRows(numOflines);
	file.clear();
	file.seekg(0,std::ios::beg);
	buildBoard(numOflines, numOfCol, &file,ghostLevel);
	file.close();
	return 1;
}

void Game::buildBoard(int rows,int cols, ifstream* file,int ghostLevel)
{
	string str;
	Ghost* ghost;
	
	for (int j = 0; j < rows; j++)
	{
		getline(*file, str);
		
		for (int i = 0; i < cols; i++)
		{
			if (str[i] == ' ')
			{
				str[i] = '*';
				board.setBreadCrumbs(board.getBreadCrumbs() + 1);	
			}
			else if (str[i] == '%')
				str[i] = ' ';
			
			else if (str[i] == '@')
			{
				pacman.setFirstP(i, j);
				pacman.setpX(i);
				pacman.setpY(j);
			}
			else if (str[i] == '$')
			{
				if(ghostLevel=='1')
					 ghost = new NoviceGhost;
				else
					 ghost = new BestGhost;

				board.setGhostCount(board.getGhostCount() + 1);
				ghostArr.push_back(ghost);
				ghostArr.back()->setpX(i);
				ghostArr.back()->setpY(j);
				ghostArr.back()->setFirstP(i, j);
			}
			else if (str[i] == '&')
			{
				board.setLegend(i, j);
			}
			board.setPos(j, i, str[i]);
			cout << board.getPos(j, i);
			

		}
		cout << "\n";
	}
	gotoxy(board.getlegendX(), board.getlegendY());
	cout << "Score:" << board.getScore();
	gotoxy(board.getlegendX(), board.getlegendY() + 1);
	cout << "life:" << pacman.getLife();
	
	for (int i = 0; i < cols; i++)
	{
		if ((board.getPos(0, i) == '*') && (board.getPos(rows - 1, i) == '*'))
		{
			gotoxy(i, 0);
			cout << '^';
			board.setPos(0, i, '^');
			gotoxy(i, rows - 1);
			cout << '^';
			board.setPos(rows-1, i, '^');
		}
	}
	for (int j = 0; j < rows; j++)
	{
		if ((board.getPos(j, 0) == '*') && (board.getPos(j, cols-1) == '*'))
		{
			gotoxy(0, j);
			cout << '^';
			board.setPos(j, 0, '^');
			gotoxy(cols - 1, j);
			cout << '^';
			board.setPos(j, cols-1, '^');
		}
	}

}

void Game::getFiles()
{
	for (const auto& entry : filesystem::directory_iterator("."))
	{
		if (entry.path().string().ends_with("screen"))
		{
			fileNames.push_back(entry.path().string());
		}
	}
}

int Game::getNumOfCurrBoard()const
{
	return num_of_curr_board;
}

void Game::setNumOfCurrBoard(int num)
{
	num_of_curr_board = num;
}

void Game::wonTheGame()//won all the maps
{
	system("CLS");
	cout << "YOU HAVE WON THE PACMAN GAME!" << endl << endl;
	cout << "PRESS ANY KEY TO GO BACK TO THE MENU";
	reset();
	pacman.setLife(3);
	while (!_kbhit()) {}
	int dummy=_getch();
	system("CLS");
}

void Game::instructions()const
{
	system("CLS");
	cout << "Instructions: " << endl;
	cout << "You control Pac-Man, who must eat all the dots inside an enclosed maze while avoiding two ghosts." << endl;
	cout << "Keys:" << endl;
	cout << "LEFT - A" << endl << "RIGHT - D" << endl << "UP - W" << endl << "DOWN - X" << endl << "STAY - S" << endl;
	cout << "GOOD LUCK!" << endl;
	cout << "Press any key to go back to menu." << endl;
	while (!_kbhit()) {}
	int dummy=_getch(); //eats the char enterd becuse we dont want the game start if we press 1 for example 
	system("CLS");
}

int Game::ghostMenu()const //gets ghost level
{
	int level;
	system("CLS");
	cout << "Please choose the level of Ghost:" << endl << endl;
	cout << "(1) EASY" << endl << endl;
	cout << "(2) MEDIUM" << endl << endl;
	cout << "(3) HARD" << endl << endl;

	level = _getch();
	while (level != '1' && level != '2' && level != '3')
	{
		if (_kbhit())
			level = _getch();
	}
	system("CLS");
	return level;
}

void Game::changeArrOfGhost(vector<Ghost*>& ghostArr, int ghostSwitcher)//change the ghost's moving algorithem
{
	Ghost* ghost;
	int size = ghostArr.size();
	point* tmpcurrP = new point[size];
	point* tmpFirstP = new point[size];

	for (int i = 0; i < size; i++)
	{
		tmpcurrP[i].setX(ghostArr[i]->getpX());
		tmpcurrP[i].setY(ghostArr[i]->getpY());
		tmpFirstP[i].setX(ghostArr[i]->getFirstPx());
		tmpFirstP[i].setY(ghostArr[i]->getFirstPy());
		delete ghostArr[i];
	}
	
	ghostArr.clear();

	for (int i = 0; i<size; i++)
	{
		if (ghostSwitcher == 1)
		{
			ghost = new NoviceGhost;
		}
		else
		{
			ghost = new BestGhost;
			
		}
		ghost->setpX(tmpcurrP[i].getX());
		ghost->setpY(tmpcurrP[i].getY());
		ghost->setFirstP(tmpFirstP[i].getX(), tmpFirstP[i].getY());
		ghostArr.push_back(ghost);
		
	}
	for (int i = 0; i < size; i++)
		ghostArr[i]->setBoard(&board);
	delete[] tmpcurrP;
	delete[] tmpFirstP; 
}

Game::~Game()
{
		for (int i = 0; i < ghostArr.size(); i++)
		{
			delete ghostArr[i];
		}
	
}


