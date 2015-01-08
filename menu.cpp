#include "menu.h"
#include "start.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
	#define WINDOWS 0
	#include "conio.h"
#elif _WIN32
	#define WINDOWS 1
	#include <conio.h>
#endif

using namespace std;

const int ENTER = 10 + WINDOWS*3;

int load()
{
	cout << "2" << '\n';
	return 0;
}

int settings()
{
	cout << "3" << '\n';
	return 0;
}

int exit()
{
	cout << "4" << '\n';
	return 0;
}

void printMenu(int i);

void menu(bool pause)
{
  int (*choice[])() = {start, load, settings, exit};
  int i = 0;
  do
  {
    printMenu(i);
    int key = getch();
    if (key == ENTER)
    {
      (*choice[i])();
      cout << "!!!";
    }
    else
      switch (key)
      {
        case 'w': case 'W':
          i = (i == 0) ? 3 : i-1;
          break;
        case 's': case 'S':
          i = (i == 3) ? 0 : i+1;
          break;
      }
    }
    while (i >= 0 && i <= 3);
  return;
}

void printMenu(int a)
{
	if (WINDOWS)
		system("cls");
	else
		system("clear");
	string txt[] = {"Start", "Load", "Setting", "Exit"};
	for (int i = 0; i < 4; i++)
    if (a == i) 
			cout << "> " << txt[i] << " < \n";
		else
			cout << txt[i] << "\n";
	return;
}
