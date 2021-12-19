#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

const int BIGUP= 87; 
const int SMALLUP = 119;
const int BIGDOWN = 88;
const int SMALLDOWN = 120;
const int BIGRIGHT = 68;
const int SMALLRIGHT = 100;
const int BIGLEFT = 65;
const int SMALLLEFT = 97;
const int BIGSTAY = 83;
const int SMALLSTAY = 115;
const int ESC = 27;
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int ROWS = 25;
const int COLS = 80;


void gotoxy(short x, short y);
	