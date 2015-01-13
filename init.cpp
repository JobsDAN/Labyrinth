// Copyright 2015 JobsDAN

#include "./map.h"
#include "./init.h"

extern int N, M;

const position notfound = {0, 0};

position getPositionPlayer(char** map) {
  position player;
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      if (map[i][j] == 'X') {
        player.y = i;
        player.x = j;
        return player;
      }
  return notfound;
}

position getPositionDoor(char** map) {
  position door;
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      if (map[i][j] == '-' || map[i][j] == '|') {
        door.y = i;
        door.x = j;
        return door;
      }
  return notfound;
}

bool equals(position a, position b) {
  return (a.x == b.x) && (a.y == b.y);
}
