#include "map.cpp"
#include "direction.cpp"
#include "init.cpp"
#include "move.h"

void move(char** map, int key)
{
	int d = getDirection(key);
	char* nextPos = player + d;
	if (*nextPos == ' ' || *nextPos == '-' || *nextPos == '|') 
	{
		*player = ' ';
		*nextPos = 'X';
		player = nextPos;
		printLocation(map);
	}
	return;
}
