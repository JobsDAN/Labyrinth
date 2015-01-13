// Copyright 2015 jobsDAN

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "./menu.h"
#include "./start.h"
#include "./records.h"
#include "./clean.h"
#include "./map.h"
#include "./game.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "multiplatform.h"
#elif _WIN32
  #define WINDOWS 1
  #include <conio.h>
#endif

const int ENTER = 10 + WINDOWS*3;

int load();
int exit();
int resume();
int mainMenu();
int pauseMenu();
void printMenu(int i, std::string[], int size);

int menu(int (**choice)(), std::string *text, int size) {
  for (int i = 0; ;) {
    printMenu(i, text, size);
    int key = getch();
    switch (key) {
      case 'w': case 'W':
        i = (i == 0) ? size-1 : i-1;
        break;
      case 's': case 'S':
        i = (i == size-1) ? 0 : i+1;
        break;
      case ENTER:
        switch ((*choice[i])()) {
          case 'q':
            return 'q';
          case 'r':
            return 1;
        }
    }
  }
  return -1;
}

void printMenu(int current, std::string *text, int size) {
  setlocale(0, "");
  clean();
  for (int i = 0; i < size; i++)
    if (i == current)
      std::cout << "> " << text[i] << " < \n";
    else
      std::cout << text[i] << "\n";
  return;
}

int main() {
  int (*choice[])() = {start, load, readRecords, exit};
  #ifdef __linux__
    std::string txt[] = {"Ð¡Ñ‚Ð°Ñ€Ñ‚", "Ð—Ð°Ð³Ñ€ÑƒÐ·ÐºÐ°", "Ð ÐµÐºÐ¾Ñ€Ð´Ñ‹", "Ð’Ñ‹Ñ…Ð¾Ð´"};
  #elif _WIN32
    std::string txt[] = {"Ñòàðò", "Çàãðóçèòü", "Ðåêîðäû", "Âûõîä"};
  #endif
  return menu(choice, txt, 4);
}

int pauseMenu() {
  int (*choice[])() = {resume, readRecords, exit};
  #ifdef __linux__
    std::string txt[] = {"ÐŸÑ€Ð¾Ð´Ð¾Ð»Ð¶Ð¸Ñ‚ÑŒ", "Ð ÐµÐºÐ¾Ñ€Ð´Ñ‹", "Ð’Ñ‹Ñ…Ð¾Ð´"};
  #elif _WIN32
    std::string txt[] = {"Ïðîäîëæèòü", "Ðåêîðäû", "Âûõîä"};
  #endif
  return menu(choice, txt, 3);
}

int resume() {
  return 'r';
}

int load() {
  char** map = getMap();
  game(map);
  return 0;
}

int exit() {
  return 'q';
}

