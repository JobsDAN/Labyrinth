#include <iostream>
#include <string>
#include "map.h"

using namespace std;

int game(char** map);

const int N_maps = 2;

int start()
{
	int stat = 1;
	string maps[N_maps] = {"standart/1.map", "standart/2.map"};
	for (int i = 0; i < N_maps; i++)
	{
		char** map = readMap(maps[i]);
		stat = game(map);
		if (stat==1)
		{
			char ans;
			cout << "YOU WIN, Continue? (y/n) ";
			cin >> ans;
			if (ans != 'y')
				return 1;
			else
				break;
		}
	}
	return 0;
}
