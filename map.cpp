// Copyright 2015 JobsDAN

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "./map.h"
#include "./clean.h"

int N, M;

char** readMap(std::string name) {
  #ifdef _WIN32
    setlocale(0, "");
  #endif
  M = 0;
  std::ifstream file(name.c_str());
  std::string line;
  getline(file, line);
  N = line.length();
  char** map = new char*[++M];
  map[0] = new char[N];
  for (int i = 0; i < N; i++)
    map[0][i] = line[i];

  while (getline(file, line)) {
    char** old_map = new char*[M];
    for (int i = 0; i < M; i++)
      old_map[i] = new char[N];

    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++)
        old_map[i][j] = map[i][j];

    for (int i = 0; i < M; i++)
      delete []map[i];

    map = new char*[++M];
    for (int i = 0; i < M; i++)
      map[i] = new char[N];

    for (int i = 0; i < M-1; i++)
      for (int j = 0; j < N; j++)
        map[i][j] = old_map[i][j];

    for (int i = 0; i < N; i++)
      map[M-1][i] = line[i];
  }
  return map;
}

char** getMap() {
  std::string name;
  #ifdef __linux__
    std::cout << "Ð’Ð²ÐµÐ´Ð¸Ñ‚Ðµ Ð¿ÑƒÑ‚ÑŒ Ðº Ñ„Ð°Ð¹Ð»Ñƒ ÑÐ¾Ð´ÐµÑ€Ð¶Ð°Ñ‰ÐµÐ¼Ñƒ ÐºÐ°Ñ€Ñ‚Ñƒ: ";
  #elif _WIN32
    std::cout << "Ââåäèòå ïóòü ê ôàéëó, ñîäåðæàùåìó êàðòó: ";
  #endif
  std::cin >> name;

  char** map = readMap(name);
  #ifdef __linux__
    std::cout << "Ð’Ð°ÑˆÐ° ÐºÐ°Ñ€Ñ‚Ð°: ";
  #elif _WIN32
    std::cout << "Âàøà êàðòà :" << '\n';
  #endif
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
      std::cout << map[i][j];
    std::cout << '\n';
  }
  return map;
}

void printMap(char** map, int steps) {
  clean();
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
      std::cout << map[i][j];
    std::cout << "\n";
  }
  #ifdef __linux__
    std::cout << "\nÐšÐ¾Ð»Ð¸Ñ‡ÐµÑÑ‚Ð²Ð¾ ÑˆÐ°Ð³Ð¾Ð²: " << steps;
  #elif _WIN32
    std::cout << "\nÊîëè÷åñòâî øàãîâ: " << steps;
  #endif
  return;
}
