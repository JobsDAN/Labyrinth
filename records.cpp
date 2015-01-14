// Copyright 2015 JobsDAN

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
  record[text.substr(0, text.rfind(' '))] = strtol((text.substr(text.rfind(' ')+1, '\n')).c_str(), NULL, 10);
  bool flag = false;
  while (getline(file, line)) {
    record[line.substr(0, line.rfind(' '))] = strtol((line.substr(line.rfind(' ')+1, '\n')).c_str(), NULL, 10);
    if (line.substr(0, line.rfind(' ')) == text.substr(0, text.rfind(' ')))
      flag = true;
    }
  if (!flag) {
    std::ofstream file("records.txt", std::ios_base::app);
    file << text << "\n";
  }
  else
    if (record[text.substr(0, text.rfind(' '))] > strtol((text.substr(text.rfind(' ')+1, '\n')).c_str(), NULL, 10)) {
      record[text.substr(0, text.rfind(' '))] = strtol((text.substr(text.rfind(' ')+1, '\n')).c_str(), NULL, 10);
      std::ofstream file("records.txt", std::ios_base::app);
      file << text << "\n";
    }
   return;         
}

int readRecords() {
  clean();
  #ifdef __linux__
    std::cout << "Ð›ÑƒÑ‡ÑˆÐ¸Ðµ Ñ€ÐµÐ·ÑƒÐ»ÑŒÑ‚Ð°Ñ‚Ñ‹\n";
  #elif _WIN32
    std::cout << "Ëó÷øèå ðåçóëüòàòû:\n";
  #endif
  std::ifstream file("records.txt");
  std::string line;
  while (getline(file, line))
    std::cout << line << "\n";
  #ifdef __linux__
    std::cout << "ÐÐ°Ð¶Ð¼Ð¸Ñ‚Ðµ ESC Ð´Ð»Ñ Ð¿Ñ€Ð¾Ð´Ð¾Ð»Ð¶ÐµÐ½Ð¸Ñ...\n";
  #elif _WIN32
    std::cout << "Íàæìèòå ESC äëÿ ïðîäîëæåíèÿ. .\n";
  #endif
  while (_getch() != 27) {}
  return 0;
}
