// Copyright 2015 JobsDAN

#include <time.h>
#include <cmath>
#include <vector>
#include "./map.h"
#include "./init.h"
#include "./move.h"
#include "./menu.h"

#ifdef __linux__
	#define WINDOWS 0
	#include "multiplatform.h"
#elif _WIN32
	#define WINDOWS 1
	#include <conio.h>
#endif

int const ESC = 27;
char *door;
double const r = 3.9; 

void refreshMap(char** curMap, char** map); 
bool inDark(char** curMap, char** map, position p);
bool canSee(char** map, position, position);
void swap(int*, int*);
void activationPos(char** curMap, char** map, position);
void activationU(char** curMap, char** map, position);
void activationLine(char** curMap, char** map, position, bool row, bool plus);

int game(char** map) {
	char** curMap = new char*[M];
	for(int i = 0; i < M; i++) {
		curMap[i] = new char[N];
		for(int j = 0; j < N; j++)
			curMap[i][j] = '.';
	}
	position door = getPositionDoor(map);
	position player = getPositionPlayer(map);
	curMap[player.y][player.x] = 'X';
	refreshMap(curMap, map);
	clock_t start = clock();
	printMap(curMap);
	while (true) {
		int key = _getch();
		if (key == ESC) {
		clock_t pause = clock();
			if (pauseMenu() == 'q'){
				start -= clock() - pause;
				delete curMap;
				return 'q';
			}
			else
				printMap(curMap);
		}
		if (move(curMap, key)){
			move(map, key);
			if (equals(getPositionPlayer(curMap), door)){
				delete curMap;
				return clock() - start;
			}
			refreshMap(curMap, map);
			printMap(curMap);
		}
	}
	_getch();
	return -1;
}

void refreshMap(char** curMap, char** map) {
	position player = getPositionPlayer(map);
	for (int i = 1; i >= 0; i--)
		for(int j = 1; j >= 0; j--)
			activationLine(curMap, map, player, i, j);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++) {
			position point = {j,i};
			bool dark = inDark(curMap, map, point);
			bool see = canSee(map, player, point);
			if (dark && see)
				activationPos(curMap, map, point);
		}
}


void activationLine(char** curMap, char** map, position p, bool row, bool plus) {
	int d = (plus ? 1 : -1);
	int x = p.x;
	int y = p.y;
	int i = 0;
	while (map[y][x] != '#' && map[y][x] != '|' && map[y][x] != '-' && i < r) {
		i++;
		position pos = {x, y};
		activationU(curMap, map, pos);
		(row ? x : y) += d;
	}
}

void activationU(char** curMap, char** map, position p) {
	for(int i = -1; i < 2; i++)
		for(int j = -1; j < 2; j++) {
			position pos = {p.x+i, p.y+j};
			activationPos(curMap, map, pos);
		}
}

void activationPos(char** curMap, char** map, position p){
	curMap[p.y][p.x] = map[p.y][p.x];
}

bool inDark(char** curMap, char** map, position p) {
	return curMap[p.y][p.x] == '.' && map[p.y][p.x] != ' ' && map[p.y][p.x] != 'X';
}

bool canSee(char** map, position a, position b) {
	bool steep = std::abs(b.y - a.y) >= std::abs(b.x - a.x);
	if (steep) {
		swap(&a.x, &a.y);
		swap(&b.x, &b.y);
	}
	if (a.x > b.x) {
		swap(&a.x, &b.x);
		swap(&a.y, &b.y);
	}
	int dx = b.x - a.x;
	int dy = std::abs(b.y - a.y);
	int dx2 = dx*dx;
	int dy2 = dy*dy;
	double l = sqrt(dx2+dy2);
	if (l > r)
		return 0;
	int error = dx / 2; 
	int ystep = (a.y < b.y) ? 1 : -1; 
	int y = a.y;
	for (int x = a.x; x < b.x; x++) {
		position current = {x, y};
		bool firts = equals(current, a);
		bool last = equals(current, b);
		bool wall = map[(steep ? x : y)][(steep ? y : x)] == '#';
		if (wall && !firts && !last)
			return 0;
		error -= dy;
		if (error < 0) {
			y += ystep;
			error += dx;
		}
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
