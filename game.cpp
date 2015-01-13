// Copyright 2015 JobsDAN

#include <time.h>
#include <iostream>
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

bool win(char**);

int game(char** map) {
  clock_t start = clock();
  position door = getPositionDoor(map);
  printMap(map);
  while (true) {
    int key = _getch();
    if (key == ESC)
      if (pauseMenu() == 'q')
        return 'q';
      else
        printMap(map);
    if (move(map, key))
      printMap(map);
	if (equals(getPositionPlayer(map), door))
      return clock() - start;
  }
  _getch();
  return -1;
}