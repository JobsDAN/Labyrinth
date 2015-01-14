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


typedef std::map<std::string, int>::iterator itMap;

std::map<std::string,int> getRecords() {
	std::ifstream file("records.txt");
	std::map<std::string, int> records;
	std::string line;
	while(getline(file, line)) {
		int lastSpace = line.rfind(' ');
		std::string strRes = line.substr(lastSpace, '\n');
		std::string name = line.substr(0, lastSpace);
		long res = strtol(strRes.c_str(), NULL, 10);
		records[name] = res;
	}
	return records;
}

void writeRecords(std::string text) {
	int lastSpace = text.rfind(' ');
	std::string name = text.substr(0, lastSpace);
	std::string strRes = text.substr(lastSpace, '\n');
	long res = strtol(strRes.c_str(), NULL, 10);
	std::map<std::string, int> records = getRecords();
	if (records.count(name) > 0 ) {
		if (records[name] > res)
			records[name] = res;
		std::ofstream file("records.txt");
		for (itMap i = records.begin(); i != records.end(); i++)
			file << i->first << " " << i->second << "\n";
	}
	else {
		records[name] = res;
		std::ofstream file("records.txt");
		for (itMap i = records.begin(); i != records.end(); i++)
			file << i->first << " " << i->second << "\n";
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
