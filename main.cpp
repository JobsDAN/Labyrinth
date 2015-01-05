#include <iostream>
#include "direction.h"
#include "map.h"
#include "init.h"
#include "move.h"
#ifdef __linux__
	#define WINDOWS 0
	#include "conio.cpp"
#elif _WIN32
	#define WINDOWS 1
	#include <conio.h>
#endif

using namespace std;

int const ESC = 27;
char *door;

int main ()
{
	char** map = getMap();
  position player, door = getPositionDoor(map);
	printLocation(map);
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		if (key == ESC)
			return 2;
		move(map, key);
		player = getPositionPlayer(map);
		if ((player.i == door.i) && (player.j == door.j))
      return 1;
	}
	getch();
	return 0;
}
