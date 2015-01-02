#include <iostream>
#ifdef __linux__ 
	#include "conio_l.cpp"
#elif _WIN32
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
};

void printLocation();
void move(int key);
Direction getDirection (int m);

char map[M][N] = {'#', '#', '#', '#', '#',
                      '#', ' ', ' ', ' ', '#',
                      '#', ' ', ' ', ' ', '#',
                      '#', ' ', ' ', ' ', '#',
                      '#', '#', '#', '/', '#'};
                      
char*player = &map[1][1];
int main ()
{
  printLocation();
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		move(key);
	}
	getch();
	return 0;
}

Direction getDirection (int m)
{
  Direction d;
  switch (m)
  {
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
  }
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
