// Copyright 2015 JobsDAN

#include <fstream>
#include <string>
#include <iostream>
#ifdef __linux__
  #define WINDOWS 0
  #include "conio.h"
#elif _WIN32
  #define WINDOWS 1
  #include <conio.h>
#endif

void writeRecords(std::string name, int record) {
  std::ofstream file("records.txt", std::ios_base::app);
  file << name << " " << record << "\n";
}

void readRecords() {
  std::ifstream file("records.txt");
  std::string line;
  while (getline(file, line))
    std::cout << line << "\n";
  return;
}
