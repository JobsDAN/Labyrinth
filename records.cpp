// Copyright 2015 JobsDAN

#include <fstream>
#include <string>
#include <iostream>
#include "clean.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "multiplatform.h"
#elif _WIN32
  #define WINDOWS 1
#include <conio.h>
#endif

void writeRecords(std::string text) {
  std::ofstream file("records.txt", std::ios_base::app);
  file << text << "\n";
}

int readRecords() {
  clean();
  #ifdef __linux__
    std::cout << "Лучшие результаты\n";
  #elif _WIN32
    std::cout << "������ ����������:\n";
  #endif
  std::ifstream file("records.txt");
  std::string line;
  while (getline(file, line))
    std::cout << line << "\n";
  #ifdef __linux__
    std::cout << "Нажмите ESC для продолжения...\n";
  #elif _WIN32
    std::cout << "������� ESC ��� �����������. .\n";
  #endif
  while (_getch() != 27) {}
  return 0;
}
