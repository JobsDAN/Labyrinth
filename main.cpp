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
