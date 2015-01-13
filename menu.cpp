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
  #include "conio.h"
#elif _WIN32
  #define WINDOWS 1
  #include <conio.h>
#endif

const int ENTER = 10 + WINDOWS*3;

int load();
int records();
int exit();
int resume();
void printMenu(int i, std::string[], int size);
int mainMenu();
int pauseMenu();

int menu(int (**choice)(), std::string *text, int size) {
  int i = 0;
  do {
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
          int a = (*choice[i])(); 
          switch (a) {
            case 'q':
              return 'q';
            case 'r':
              return 1;
          }
      }
  } while (i >= 0 && i <= size-1);
  return -1;
}

int mainMenu() {
  int (*choice[])() = {start, load, records, exit};
  #ifdef __linux__
    std::string txt[] = {"Ð¡Ñ‚Ð°Ñ€Ñ‚", "Ð—Ð°Ð³Ñ€ÑƒÐ·ÐºÐ°", "Ð ÐµÐºÐ¾Ñ€Ð´Ñ‹", "Ð’Ñ‹Ñ…Ð¾Ð´"};
  #elif _WIN32
    std::string txt[] = {"Ñòàðò", "Çàãðóçèòü", "Ðåêîðäû", "Âûõîä"};
  #endif
  return menu(choice, txt, 4);
}

int pauseMenu() {
  int (*choice[])() = {resume, records, exit};
  #ifdef __linux__
    std::string txt[] = {"ÐŸÑ€Ð¾Ð´Ð¾Ð»Ð¶Ð¸Ñ‚ÑŒ", "Ð ÐµÐºÐ¾Ñ€Ð´Ñ‹", "Ð’Ñ‹Ñ…Ð¾Ð´"};
  #elif _WIN32
    std::string txt[] = {"Ïðîäîëæèòü", "Ðåêîðäû", "Âûõîä"};
  #endif
  return menu(choice, txt, 3);
}

void printMenu(int current, std::string *text, int size) {
  #ifdef _WIN32
    setlocale(0, "");
  #endif
  clean();
  for (int i = 0; i < size; i++)
    if (i == current)
      std::cout << "> " << text[i] << " < \n";
    else
      std::cout << text[i] << "\n";
  return;
}

int records() {
  clean();
  #ifdef __linux__
    std::cout << "Ð›ÑƒÑ‡ÑˆÐ¸Ðµ Ñ€ÐµÐ·ÑƒÐ»ÑŒÑ‚Ð°Ñ‚Ñ‹\n";
  #elif _WIN32
    std::cout << "Ëó÷øèå ðåçóëüòàòû:\n";
  #endif
  readRecords();
  #ifdef __linux__
    std::cout << "ÐÐ°Ð¶Ð¼Ð¸Ñ‚Ðµ ESC Ð´Ð»Ñ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶ÐµÐ½Ð¸Ñ...\n";
  #elif _WIN32
    std::cout << "Íàæìèòå ESC äëÿ ïðîäîëæåíèÿ. .\n";
  #endif
  while (getch() != 27) {}
  return 0;
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

