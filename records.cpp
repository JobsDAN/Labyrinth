// Copyright 2015 JobsDAN

#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include "clean.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "multiplatform.h"
#elif _WIN32
  #define WINDOWS 1
#include <conio.h>
#endif

int findName(std::string line);

void writeRecords(std::string text) {
  std::ifstream file("records.txt");
  std::string line;
  std::map <std::string, int> record;
  long tempTextRes = strtol((text.substr(text.rfind(' ') + 1, '\n')).c_str(), NULL, 10);
  std::string tempTextName = text.substr(0, text.rfind(' '));
  bool flag = false;
  while (getline(file, line)) {
	  std::string tempLineName = line.substr(0, line.rfind(' '));
	  long tempLineRes = strtol((line.substr(line.rfind(' ') + 1, '\n')).c_str(), NULL, 10);
	  record[tempLineName] = tempLineRes;
	  if (tempLineName == tempTextName) {
		  if (record[tempLineName] > tempTextRes)
			  record[tempLineName] = tempTextRes;
		  flag = true;
	  }
  }
  if (!flag) {
    std::ofstream file("records.txt", std::ios_base::app);
    file << text << "\n";
  }
   return;         
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
