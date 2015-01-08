#include <conio.h>
#include "menu.h"

void start()
{
  cout << "1";
  return;
};
void load()
{
  cout << "2";
  return;
};
void settings()
{
  cout << "3";
  return;
};
void exit()
{
  cout << "4";
  return;
};

void printMenu(int i);

void menu(bool pause)
{
  void (*choice[])() = {start, load, settings, exit};
  int i = 0;
  do
  {
    printMenu(i);
    int key = getch();
    if (key == 10)
      (*choice[i])();
    else
      switch (key)
      {
        case 'w': case 'W':
          i = (i == 0) ? i-1 : 3;
          break;
        case 's': case 'S':
          i = (i == 3) ? i+1 : 0;
          break;
      }
    }
    while (i >= 0 && i <= 3);
  return;
}

void printMenu(int i)
{
  system("cls");
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
