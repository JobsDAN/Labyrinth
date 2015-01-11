// Copyright 2015 jobsDAN

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "menu.h"
#include "start.h"
#include "records.h"
#include "clean.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "conio.h"
#elif _WIN32
  #define WINDOWS 1
  #include <conio.h>
#endif

const int ENTER = 10 + WINDOWS*3;
const int N_menu = 4;
int load() {
  cout << "2" << '\n';
  return 0;
}

int records() {
  clean();
  cout << "Your records:\n";
  readRecords();
  cout << "Press ESC for return";
  while (getch() != 27) {}
  return 0;
}
int exit() {
  return 'q';
}

void printMenu(int i);

int menu(bool pause) {
  int (*choice[])() = {start, load, records, exit};
  int i = 0;
  do {
    printMenu(i);
    int key = getch();
    if (key == ENTER) {
      int a = (*choice[i])();
      if (a == 'q')
        return 'q';
    } else {
      switch (key) {
        case 'w': case 'W':
          i = (i == 0) ? N_menu-1 : i-1;
          break;
        case 's': case 'S':
          i = (i == N_menu-1) ? 0 : i+1;
          break;
      }
    }
  }
  while (i >= 0 && i <= N_menu-1) {}
  return -1;
}

void printMenu(int a) {
  clean();
  string txt[] = {"Start", "Load", "Records", "Exit"};
  for (int i = 0; i < 4; i++)
    if (a == i)
      cout << "> " << txt[i] << " < \n";
    else
      cout << txt[i] << "\n";
  return;
}
