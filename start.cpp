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
    std::cout << "\nНажмите любую клавишу для продолжения...";
  #elif _WIN32
    std::cout << "\n������� ����� ������� ��� �����������. . .";
  #endif
  _getch();
 #ifdef __linux__
  _getch();
 #endif
}

void printWinMessage() {
  #ifdef __linux__
    std::cout << "\nВы прошли все уровни. Поздравляем!\n"
              << "Введите ваше имя: ";
  #elif _WIN32
	std::cout << "\n�� ������ ��� ������. �����������!\n"
		<< "������� ���� ���: ";
  #endif
}
