#include <iostream>
#include <string>
#include <conio.h>
#include "map.h"
#include "records.h"

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
		if (stat != 'q')
		{
			char ans;
			cout << "\nYOU WON!!!\nEnter your name:\n";
			string name;
			cin >> name;
			if (name != "")
        writeRecords(name, stat);
      if (i == N_maps - 1)
      {
        cout << "You have finished all maps. CONGRATULATIONS!\nPress any key. . .";
        getch();
        return 1;
      }
      cout << "Continue? (y/n)\n";
      cin >> ans;
			if (ans != 'y')
				return 'q';
		}
		else 
			return 'q';
	}
	return 0;
}
