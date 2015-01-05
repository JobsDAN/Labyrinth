#include "map.h"

extern int N, M;
struct position
{
	int i, j;
};

const position notfound = {0,0};

position getPositionPlayer(char** map)
{
	position player;
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == 'X')
			{
				player.i = i;
				player.j = j;
				return player;
			}
	return notfound;
}

position getPositionDoor(char** map)
{
	position door;
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == '-' || map[i][j] == '|')
			{
				door.i = i;
				door.j = j;
				return door;
			}
	return notfound;
}
