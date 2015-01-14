// Copyright 2015 JobsDAN

#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <time.h>
#include "clean.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "multiplatform.h"
#elif _WIN32
  #define WINDOWS 1
#include <conio.h>
#endif

typedef std::map<std::string, int>::iterator itMap;
const char fileRecords[] = "records.dat";

long double printTime(std::string line, int lastSpace) {
	std::string strRes = line.substr(lastSpace, '\n');
	double res = strtod(strRes.c_str(), NULL);
	float time = (res/1000);
	return time;
}

std::map<std::string,int> getRecords() {
	std::ifstream file(fileRecords);
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
	
	bool nameExist = records.count(name) > 0;
	bool newRecord = records[name] > res;
	if (!nameExist || newRecord) { // a -> b <=> !a || b
		records[name] = res;
		std::ofstream file(fileRecords);
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
  std::ifstream file(fileRecords);
  std::string line;
  double res;
  while (getline(file, line)) {
    int lastSpace = line.rfind(' ');
		std::string name = line.substr(0, lastSpace);
    std::cout << name << " " << printTime(line, lastSpace) << "s \n";
  }
  #ifdef __linux__
    std::cout << "Нажмите ESC для продолжения...\n";
  #elif _WIN32
    std::cout << "������� ESC ��� �����������. . .\n";
  #endif
  while (_getch() != 27) {}
  return 0;
}
