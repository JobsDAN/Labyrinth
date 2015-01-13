// Copyright 2015 JobsDAN

#include "./map.h"
#include "./move.h"
#include "./init.h"


int move(char** map, int key) {
  position nextPos = getPositionPlayer(map);
  position oldPos = nextPos;
  switch (key) {
    case 'w': case 'W':
      nextPos.y--;
      break;
    case 'a': case 'A':
      nextPos.x--;
      break;
    case 's': case 'S':
      nextPos.y++;
      break;
    case 'd': case 'D':
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
