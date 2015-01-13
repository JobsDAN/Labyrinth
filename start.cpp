// Copyright 2015 JobsDAN

#include <iostream>
#include <sstream>
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
      if (i == N_maps - 1) {
        #ifdef __linux__
          std::cout << "\nВы прошли все уровни. Поздравляем!!\n"
                    << "Нажмите любую клавишу для продолжения...";
        #elif _WIN32
          std::cout << "�� ������ ��� ������. �����������!\n"
               << "������� ���� ���: ";
        #endif
        std::string name;
        std::cin >> name;
        if (name != "") {
          std::stringstream text;
          text << name << " " << stat;
          writeRecords(text.str());
        }
        #ifdef __linux__
          std::cout << "\nНажмите любую клавишу для продолжения...";
        #elif _WIN32
          std::cout << "\n������� ����� ������� ��� �����������. . .";
        #endif
        getch();
        return 1;
      }
    }
  }
  return 0;
}
