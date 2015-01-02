#include <iostream>
#include <stdlib.h>
#ifdef __linux__
	#define WINDOWS 0
	#include "conio_l.cpp"
#elif _WIN32
	#define WINDOWS 1
	#include <conio.h>
#endif

using namespace std;

int const N = 5;
int const M = 6;
int const ESC = 27;
enum Direction
{
  UP = -N,
  DOWN = N,
  LEFT = -1,
  RIGHT = 1,
  ERROR = 0
};

void printLocation();
char map[M][N] = {'#', '#', '#', '#', '#',
                  '#', 'X', ' ', ' ', '#',
                  '#', ' ', ' ', ' ', '#',
                  '#', ' ', ' ', ' ', '#',
                  '#', '#', '#', '-', '#'};
char *player, *door;
void move(int key);
Direction getDirection (int m);
char* getPositionPlayer();
char* getPositionDoor();

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

char* getPositionDoor()
{
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == '-' || map[i][j] == '|')
				return &map[i][j];
}

char* getPositionPlayer()
{
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == 'X')
				return &map[i][j];
}

Direction getDirection (int m)
{
	Direction d;
	switch (m){
	case 'w': case 'W':
		d = UP;
		return d;
	case 's': case 'S':
		d = DOWN;
		return d;
	case 'a': case 'A':
		d = LEFT;
		return d;
	case 'd': case 'D':
		d = RIGHT;
		return d;
	default:
		d = ERROR;
		return d;}
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
