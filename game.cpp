// Copyright 2015 JobsDAN

#include <iostream>
#include "./map.h"
#include "./init.h"
#include "./move.h"
#include "./menu.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "conio.h"
#elif _WIN32
  #define WINDOWS 1
  #include <conio.h>
#endif

int const ESC = 27;
char *door;

int game(char** map) {
  position player, door = getPositionDoor(map);
  int steps = 0;
  printMap(map, steps);
  bool quit = false;
  while (!quit) {
    int key = getch();
    if (key == ESC) {
      if (menu(true) == 'q')
        return 'q';
      printMap(map, steps);
    }
    if (move(map, key))
      printMap(map, ++steps);
    player = getPositionPlayer(map);
    if ((player.i == door.i) && (player.j == door.j))
      return steps;
  }
  getch();
  return -1;
}
