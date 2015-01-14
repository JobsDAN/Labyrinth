// Copyright 2015 JobsDAN

#include <time.h>
#include <iostream>
#include <sstream>
#include <string>
#include "./map.h"
#include "./records.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "multiplatform.h"
#elif _WIN32
  #define WINDOWS 1
#include <conio.h>
#endif

int game(char** map);

const int N_maps = 3;

void printWinMessage();
void pressAnyKey();

int start() {
  #ifdef _WIN32
    setlocale(0, "");
  #endif
  double time = 0;
  std::string maps[N_maps] = {"1", "2", "3"};
  for (int i = 0; i < N_maps; i++) {
    char** map = readMap("standart/" + maps[i] + ".map");
	int res = game(map);
    if (res != 'q') {
      time += res;
      if (i == N_maps - 1) {
        printWinMessage();
        std::string name;
        std::cin >> name;
        std::stringstream text;
        text << name << " " << time;
        writeRecords(text.str());
        pressAnyKey();
        return 1;
      }
    }
  }
  return 0;
}

void pressAnyKey() {
  #ifdef __linux__
    std::cout << "\nÐÐ°Ð¶Ð¼Ð¸Ñ‚Ðµ Ð»ÑŽÐ±ÑƒÑŽ ÐºÐ»Ð°Ð²Ð¸ÑˆÑƒ Ð´Ð»Ñ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶ÐµÐ½Ð¸Ñ...";
  #elif _WIN32
    std::cout << "\nÍàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ. . .";
  #endif
  _getch();
 #ifdef __linux__
  _getch();
 #endif
}

void printWinMessage() {
  #ifdef __linux__
    std::cout << "\nÐ’Ñ‹ Ð¿Ñ€Ð¾ÑˆÐ»Ð¸ Ð²ÑÐµ ÑƒÑ€Ð¾Ð²Ð½Ð¸. ÐŸÐ¾Ð·Ð´Ñ€Ð°Ð²Ð»ÑÐµÐ¼!\n"
              << "Ð’Ð²ÐµÐ´Ð¸Ñ‚Ðµ Ð²Ð°ÑˆÐµ Ð¸Ð¼Ñ: ";
  #elif _WIN32
	std::cout << "\nÂû ïðîøëè âñå óðîâíè. Ïîçäðàâëÿåì!\n"
		<< "Ââåäèòå âàøå èìÿ: ";
  #endif
}
