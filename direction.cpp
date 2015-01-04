#include "direction.h"
#include "map.h"

int getDirection (int key)
{
	switch (key){
	case 'w': case 'W':
		return -N;
	case 's': case 'S':
		return N;
	case 'a': case 'A':
		return -1;
	case 'd': case 'D':
		return 1;
	default:
		return 0;}
}
