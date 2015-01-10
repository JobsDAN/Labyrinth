#include "map.h"
#include "clean.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int N, M;

char** readMap(string name)
{
	M = 0;
	ifstream file(name.c_str());
	string line;
	getline(file, line);
	N = line.length();
	char** map = new char*[++M];
	map[0] = new char[N];
	for (int i = 0; i < N; i++)
		map[0][i] = line[i];

	while(getline(file, line))
	{
		char** old_map = new char*[M];
		for (int i = 0; i < M; i++)
			old_map[i] = new char[N];
		
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				old_map[i][j] = map[i][j];
		
		for (int i = 0; i < M; i++)
			delete []map[i];
		
		map = new char*[++M];
		for (int i = 0; i < M; i++)
			map[i] = new char[N];
		
		for (int i = 0; i < M-1; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = old_map[i][j];
		
		for (int i = 0; i < N; i++)
			map[M-1][i] = line[i];
	}
	
	return map;
}

char** getMap()
{
	string name;
	cout << "Enter name file with map: ";
	cin >> name;
	
	char** map = readMap(name);
	cout << "Your map:" << '\n';
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << '\n';
	}
	return map;
}

void printLocation(char** map)
{
	clean();
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << "\n";
	}      
	return;
}
