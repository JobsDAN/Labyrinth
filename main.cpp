#include <iostream>
#ifdef __linux__ 
	#include "conio_l.cpp"
#elif _WIN32
	#include <conio.h>
#endif

using namespace std;

int const N = 5;
int const M = 6;

void printLocation(char a[M][N])
{
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
      cout << a[i][j];
    cout << "\n";
  }      
  return;
}
enum Direction
{
  UP = -N;
  DOWN = N;
  LEFT = -1;
  RIGHT = 1;
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
int main ()
{
  char a[M][N] = {'#', '#', '#', '#', '#',
                  '#', ' ', ' ', ' ', '#',
                  '#', ' ', ' ', ' ', '#',
                  '#', ' ', ' ', ' ', '#',
                  '#', '#', '#', '/', '#'};
  printLocation(a);
  getch();
  return 0;
}
