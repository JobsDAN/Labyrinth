#include <iostream>
#ifdef __linux__ 
	#include "conio_l.cpp"
#elif _WIN32
	#include <conio.h>
#endif

using namespace std;

int const N = 5;
int const M = 6;

void printLocation(char map[M][N]);
void move(int key);

int main ()
{
	char map[M][N] = {'#', '#', '#', '#', '#',
                      '#', ' ', ' ', ' ', '#',
                      '#', ' ', ' ', ' ', '#',
                      '#', ' ', ' ', ' ', '#',
                      '#', '#', '#', '/', '#'};
	printLocation(map);
	bool quit = false;
	while (!quit)
	{
		int key = getch();
		move(key);
	}
	getch();
	return 0;
}

void printLocation(char map[M][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << "\n";
	}      
	return;
}

