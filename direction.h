#include "map.h"

enum Direction
{
  UP = -N,
  DOWN = N,
  LEFT = -1,
  RIGHT = 1,
  ERROR = 0
};

// На выходе выдает направление, которое соответствует нажатой клавише
Direction getDirection(int key);
