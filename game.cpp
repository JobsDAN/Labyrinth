#include <iostream>
#include "map.h"
#include "init.h"
#include "move.h"
#include "menu.h" 
#ifdef __linux__
	#define WINDOWS 0
	#include "conio.h"
#elif _WIN32
	#define WINDOWS 1
	#include <conio.h>
#endif

using namespace std;

int const ESC = 27;
char *door;

int game (char** map)
{
	//char** map = getMap();
	position player, door = getPositionDoor(map);
	printLocation(map);
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		if (key == ESC)
		{
			int a = menu(true);
			if (a == 'q')
				return 2;
			printLocation(map);
		}
		move(map, key);
		player = getPositionPlayer(map);
		if ((player.i == door.i) && (player.j == door.j))
			return 1;
	}
	getch();
	return -1;
}
