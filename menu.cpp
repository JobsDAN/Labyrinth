// Copyright 2015 jobsDAN

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "menu.h"
#include "start.h"
#include "records.h"
#include "clean.h"
#include "map.h"
#include "game.h"
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
  char** map = getMap();
  game(map);
  return 0;
}

int records() {
  clean();
  #ifdef __linux__
    std::cout << "Ð›ÑƒÑ‡ÑˆÐ¸Ðµ Ñ€ÐµÐ·ÑƒÐ»ÑŒÑ‚Ð°Ñ‚Ñ‹\n";
  #elif _WIN32
    std::cout << "Âàøè ðåêîðäû:\n";
  #endif
  readRecords();
  #ifdef __linux__
    std::cout << "ÐÐ°Ð¶Ð¼Ð¸Ñ‚Ðµ ESC Ð´Ð»Ñ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶ÐµÐ½Ð¸Ñ...\n";
  #elif _WIN32
    std::cout << "Íàæìèòå ESC äëÿ âîçâðàùåíèÿ â ìåíþ. . .\n";
  #endif
  while (getch() != 27) {}
  return 0;
}

int exit() {
  return 'q';
}

void printMenu(int i);

int menu(bool pause) {
  #ifdef _WIN32
    setlocale(0, "");
  #endif
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
  } while (i >= 0 && i <= N_menu-1);
  return -1;
}

void printMenu(int a) {
  clean();
  #ifdef __linux__
    std::string txt[] = {"Ð¡Ñ‚Ð°Ñ€Ñ‚", "Ð—Ð°Ð³Ñ€ÑƒÐ·ÐºÐ°", "Ð ÐµÐºÐ¾Ñ€Ð´Ñ‹", "Ð’Ñ‹Ñ…Ð¾Ð´"};
  #elif _WIN32
    std::string txt[] = {"Ñòàðò", "Çàãðóçêà", "Ðåêîðäû", "Âûõîä"};
  #endif
  for (int i = 0; i < 4; i++)
    if (a == i)
      std::cout << "> " << txt[i] << " < \n";
    else
      std::cout << txt[i] << "\n";
  return;
}
