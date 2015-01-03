#include "map.h"

extern char map[M][N];

char* getPositionDoor()
{
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == '-' || map[i][j] == '|')
				return &map[i][j];
	return 0;
}

char* getPositionPlayer()
{
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == 'X')
				return &map[i][j];
	return 0;
}
