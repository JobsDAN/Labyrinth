// Copyright 2015 JobsDAN

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "./map.h"
#include "./clean.h"
#ifdef __linux__
	#include "multiplatform.h"
#endif

int N, M;

std::string readPath();
void printError();
char** newArray(int, int);
void deleteArray(char**, int);
void copyArray(char** from, char** to, int M, int N);
void copyLine(const char* from, char* to, int N);

char** readMap(std::string name) {
	setlocale(0, "");
	std::ifstream file(name.c_str());
	std::string line;
	getline(file, line);
	N = line.length();
	M = 0;
	
	char** map = newArray(++M, N);
	copyLine(line.c_str(), map[0], N);
	
	while (getline(file, line)) {
		char** oldMap = newArray(M,N);
		copyArray(map, oldMap, M, N);
		deleteArray(map, M);
		map = newArray(++M, N);
		copyArray(oldMap, map, M-1, N);
		copyLine(line.c_str(), map[M-1], N);
	}
	return map;
}

char** newArray(int M, int N) {
	char** a = new char*[M];
	for (int i = 0; i < M; i++)
		a[i] = new char[N];
	return a;
}

void deleteArray(char** a, int N) {
	for (int i = 0; i < N; i++)
		delete []a[i];
}

void copyLine(const char* from, char* to, int N) {
	for (int i = 0; i < N; i++)
		to[i] = from[i];
}

void copyArray(char** from, char** to, int M, int N) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			to[i][j] = from[i][j];
}

char** getMap() {
	do {
		std::string path = readPath();
		std::ifstream file(path.c_str());
		if (file.good()){
			char** map = readMap(path);
			return map;
		}
		else
			printError();
	} while(true);
}

void printError() {
	#ifdef __linux__
		std::cout << "Такого файла не существует.\n";
	#elif WIN32
		std::cout << "?????? ????? ?? ??????????.\n";
	#endif
}

void printMap(char** map) {
  clean();
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
      std::cout << map[i][j];
    std::cout << "\n";
  }
  return;
}

std::string readPath() {
  #ifdef __linux__
    std::cout << "Введите путь к файлу содержащему карту: ";
  #elif _WIN32
    std::cout << "??????? ???? ? ?????, ??????????? ?????: ";
  #endif
  std::string name;
  std::cin >> name;
  return name;
}
