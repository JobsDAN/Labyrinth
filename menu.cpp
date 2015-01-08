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
		if (key == 10)
		{
			(*choice[i])();
		}
		else
			switch (key)
			{
			case 'w': case 'W':
				if (i != 0)
					i--;
				else
					i = 3;
				break;
			case 's': case 'S':
				if (i != 3)
					i++;
				else
					i = 0;
				break;
			}
	}
	while ( i>=0 && i <= 3);
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
	{
		if (a == i) 
			cout << "> ";
		cout << txt[i];
		if (a == i)
			cout << " < \n";
		else
			cout << '\n';
	}
}
/*
	switch(i)
	{
	case 0:
		cout << "> Start <\nLoad\nSettings\nExit\n";
		return;
	case 1:
		cout << "Start\n> Load <\nSettings\nExit\n";
		return;
	case 2:
		cout << "Start\nLoad\n> Settings <\nExit\n";
		return;
	case 3:
		cout << "Start\nLoad\nSettings\n> Exit <\n";
		return;
	}
}
*/
