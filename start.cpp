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
	setlocale(0,"");
  int stat = 1;
	string maps[N_maps] = {"standart/1.map", "standart/2.map"};
	for (int i = 0; i < N_maps; i++)
	{
		char** map = readMap(maps[i]);
		stat = game(map);
		if (stat != 'q')
		{
			char ans;
			cout << "\n�� ��������!!!\n������� ���� ���:\n";
			string name;
			cin >> name;
			if (name != "")
        writeRecords(name, stat);
      if (i == N_maps - 1)
      {
        cout << "�� ������ ��� �����. �����������!\n������� ����� �������. . .";
        getch();
        return 1;
      }
      cout << "����������? (y/n)\n";
      cin >> ans;
			if (ans != 'y')
				return 'q';
		}
		else 
			return 'q';
	}
	return 0;
}
