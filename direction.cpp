#include "direction.h"

Direction getDirection (int key)
{
	Direction d;
	switch (key){
	case 'w': case 'W':
		d = UP;
		return d;
	case 's': case 'S':
		d = DOWN;
		return d;
	case 'a': case 'A':
		d = LEFT;
		return d;
	case 'd': case 'D':
		d = RIGHT;
		return d;
	default:
		d = ERROR;
		return d;}
}
