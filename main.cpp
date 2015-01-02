#include <iostream>
#ifdef __linux__
	#define Windows 0
	#include "conio_l.cpp"
#elif _WIN32
	#define Windows 1
	#include <conio.h>
#endif

using namespace std;

int const N = 5;
int const M = 6;

enum Direction
{
  UP = -N,
  DOWN = N,
  LEFT = -1,
  RIGHT = 1,
  ERROR = 0
};

void printLocation();
char map[M][N] = {'#', '#', '#', '#', '#',
                  '#', 'X', ' ', ' ', '#',
                  '#', ' ', ' ', ' ', '#',
                  '#', ' ', ' ', ' ', '#',
                  '#', '#', '#', '/', '#'};
char* player;
void move(int key);
Direction getDirection (int m);
char* getPosition();
                      
int main ()
{
  printLocation();
	player = getPosition();
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		move(key);
	}
	getch();
	return 0;
}

char* getPosition()
{
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if (map[i][j] == 'X') 
				return &map[i][j];
}

Direction getDirection (int m)
{
	Direction d;
	switch (m){
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

void printLocation()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << "\n";
	}      
	return;
}

void move(int key)
{
  Direction m = getDirection(key);
  if (*(player + m) == ' ') 
  {
    *player = ' ';
    player += m;
    *player = 'X';
    printLocation();
  }
  return;
}
