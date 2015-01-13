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
  printMap(map);
  while (true) {
    int key = getch();
    if (key == ESC)
      if (pauseMenu() == 'q')
        return 'q';
      else
        printMap(map);
    if (move(map, key))
      printMap(map);
    if (win(map))
      return clock() - start;
  }
  getch();
  return -1;
}

bool win(char** map) {
  return equals(getPositionDoor(map), getPositionPlayer(map));
}
