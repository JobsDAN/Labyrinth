// Copyright 2015 JobsDAN

#include <iostream>
#include <string>
#include "./map.h"
#include "./records.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "conio.h"
#elif _WIN32
  #define WINDOWS 1
  #include <conio.h>
#endif

int game(char** map);

const int N_maps = 2;

int start() {
  #ifdef _WIN32
    setlocale(0, "");
  #endif
  int stat = 1;
  std::string maps[N_maps] = {"standart/1.map", "standart/2.map"};
  for (int i = 0; i < N_maps; i++) {
    char** map = readMap(maps[i]);
    stat = game(map);
    if (stat != 'q') {
      char ans;
      #ifdef __linux__
        std::cout << "\nÐ’Ñ‹ Ð¿Ð¾Ð±ÐµÐ´Ð¸Ð»Ð¸!!!\nÐ’Ð²ÐµÐ´Ð¸Ñ‚Ðµ Ð’Ð°ÑˆÐµ Ð¸Ð¼Ñ:\n";
      #elif _WIN32
        std::cout << "\nÂû ïîáåäèëè!!!\nÂâåäèòå âàøå èìÿ: ";
      #endif
      std::string name;
      std::cin >> name;
      if (name != "")
        writeRecords(name, stat);
      if (i == N_maps - 1) {
        #ifdef __linux__
          std::cout << "\nÐ’Ñ‹ Ð¿Ñ€Ð¾ÑˆÐ»Ð¸ Ð²ÑÐµ ÑƒÑ€Ð¾Ð²Ð½Ð¸. ÐŸÐ¾Ð·Ð´Ñ€Ð°Ð²Ð»ÑÐµÐ¼!!\n"
                    << "ÐÐ°Ð¶Ð¼Ð¸Ñ‚Ðµ Ð»ÑŽÐ±ÑƒÑŽ ÐºÐ»Ð°Ð²Ð¸ÑˆÑƒ Ð´Ð»Ñ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶ÐµÐ½Ð¸Ñ...";
        #elif _WIN32
          std::cout << "Âû ïðîøëè âñå óðîâíè. Ïîçäðàâëÿåì!\n"
               << "Íàæìèòå ëþáóþ êëàâèøó äëÿ ïðîäîëæåíèÿ. . .";
        #endif
        getch();
        return 1;
      }
      #ifdef __linux__
        std::cout << "Ð¥Ð¾Ñ‚Ð¸Ñ‚Ðµ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶Ð¸Ñ‚ÑŒ? (y/n)\n";
      #elif _WIN32
        std::cout << "Õîòèòå ïðîäîëæèòü? (y/n)\n";
      #endif
      std::cin >> ans;
      if (ans != 'y')
        return 'q';
    } else {
      return 'q';
    }
  }
  return 0;
}
