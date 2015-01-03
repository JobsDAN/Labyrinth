#include <iostream>
#include <stdlib.h>
#include "direction.h"
#include "map.h"
#include "init.h"
#ifdef __linux__
	#define WINDOWS 0
	#include "conio.cpp"
#elif _WIN32
	#define WINDOWS 1
	#include <conio.h>
#endif

using namespace std;

int const ESC = 27;
extern char map[M][N];
char *player, *door;
void printLocation();
void move(int key);

int main ()
{
	player = getPositionPlayer();
	door = getPositionDoor();
	printLocation();
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		if (key == ESC)
			return 2;
		move(key);
		if (player == door) 
			return 1;
	}
	getch();
	return 0;
}

void printLocation()
{
	if (WINDOWS)
		system("cls");
	else
		system("clear");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << "\n";
	}      
	return;
}

void move(int key)
{
  char* nextPos = player + getDirection(key);
  if (*nextPos == ' ' || *nextPos == '-' || *nextPos == '|') 
  {
    *player = ' ';
	  *nextPos = 'X';
    player = nextPos;
    printLocation();
  }
  return;
}
