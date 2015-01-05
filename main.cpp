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
char *door;
void move(char** map, int key);

int main ()
{
	char** map = getMap();
	printLocation(map);
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		if (key == ESC)
			return 2;
		move(map, key);
	}
	getch();
	return 0;
}
