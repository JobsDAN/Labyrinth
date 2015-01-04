#include "map.h"

char* getPositionDoor(char** map)
{
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == '-' || map[i][j] == '|')
				return &map[i][j];
	return 0;
}

char* getPositionPlayer(char** map)
{
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == 'X')
				return &map[i][j];
	return 0;
}
