#ifndef MAP_H
#define MAP_H
#include <iostream>

extern int M; 
extern int N;

char** getMap();
char** readMap(std::string name);
void printMap(char** map);

#endif
