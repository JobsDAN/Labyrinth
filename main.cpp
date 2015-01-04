#include <iostream>
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
char *player, *door;
void move(char** map, int key);

int main ()
{
	char** map = getMap();
	player = getPositionPlayer(map);
	door = getPositionDoor(map);
	printLocation(map);
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		if (key == ESC)
			return 2;
		move(map, key);
		if (player == door) 
			return 1;
	}
	getch();
	return 0;
}

void move(char** map, int key)
{
	int d = getDirection(key);
	char* nextPos = player + d;
	if (*nextPos == ' ' || *nextPos == '-' || *nextPos == '|') 
	{
		*player = ' ';
		*nextPos = 'X';
		player = nextPos;
		printLocation(map);
	}
	return;
}

