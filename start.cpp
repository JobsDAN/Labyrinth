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
        std::cout << "\nВы победили!!!\nВведите Ваше имя:\n";
      #elif _WIN32
        std::cout << "\nÂû ïîáåäèëè!!!\nÂâåäèòå âàøå èìÿ:\n";
      #endif
      std::string name;
      std::cin >> name;
      if (name != "")
        writeRecords(name, stat);
      if (i == N_maps - 1) {
        #ifdef __linux__
          std::cout << "\nВы прошли все уровни. Поздравляем!!\n"
                    << "Нажмите любую клавишу для продолжения...";
        #elif _WIN32
          std::cout << "Âû ïðîøëè âñå êàðòû. Ïîçäðàâëÿåì!\n"
               << "Íàæìèòå ëþáóþ êëàâèøó. . .";
        #endif
        getch();
        return 1;
      }
      #ifdef __linux__
        std::cout << "Хотите продолжить? (y/n)\n";
      #elif _WIN32
        std::cout << "Ïðîäîëæèòü? (y/n)\n";
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
