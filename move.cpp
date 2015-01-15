// Copyright 2015 JobsDAN

#include "./map.h"
#include "./move.h"
#include "./init.h"
#include <iostream>

#ifdef __linux__
	#define WINDOWS 0
	#include "multiplatform.h"
	int const W = 134;
	int const A = 132;
	int const S = 139;
	int const D = 178;
#elif _WIN32
	#define WINDOWS 1
	#include <conio.h>
	int const W = 230;
	int const A = 228;
	int const S = 235;
	int const D = 162;
#endif

int move(char** map, int key) {
	position nextPos = getPositionPlayer(map);
	position oldPos = nextPos;
	switch (key) {
		case 'w': case 'W': case W:
			nextPos.y--;
			break;
		case 'a': case 'A': case A:
			nextPos.x--;
			break;
		case 's': case 'S': case S:
			nextPos.y++;
			break;
		case 'd': case 'D': case D:
			nextPos.x++;
			break;
		default:
			break;
	}
	char *pNextPos = &map[nextPos.y][nextPos.x];
	if (*pNextPos == ' ' || *pNextPos == '-' || *pNextPos == '|') {
		map[oldPos.y][oldPos.x] = ' ';
		*pNextPos = 'X';
		return 1;
	}
	return 0;
}
