// Copyright 2015 JobsDAN

#include "./map.h"
#include "./move.h"
#include "./init.h"


int move(char** map, int key) {
  position nextPos = getPositionPlayer(map);
  position oldPos = nextPos;
  switch (key) {
    case 'w': case 'W':
      nextPos.i--;
      break;
    case 'a': case 'A':
      nextPos.j--;
      break;
    case 's': case 'S':
      nextPos.i++;
      break;
    case 'd': case 'D':
      nextPos.j++;
      break;
    default:
      break;
  }
  char *pNextPos = &map[nextPos.i][nextPos.j];
  if (*pNextPos == ' ' || *pNextPos == '-' || *pNextPos == '|') {
    map[oldPos.i][oldPos.j] = ' ';
    *pNextPos = 'X';
    return 1;
  }
  return 0;
}
