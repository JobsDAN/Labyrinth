#include "map.h"

enum Direction
{
  UP = -N,
  DOWN = N,
  LEFT = -1,
  RIGHT = 1,
  ERROR = 0
};

Direction getDirection(int key);
