// Copyright 2015 JobsDAN

#include <iostream>
#include <string>
#include "map.h"
#include "records.h"
#ifdef __linux__
  #define WINDOWS 0
  #include "conio.h"
#elif _WIN32
  #define WINDOWS 1
  #include <conio.h>
#endif

int game(char** map);

const int N_maps = 2;

int start() {
  int stat = 1;
  string maps[N_maps] = {"standart/1.map", "standart/2.map"};
  for (int i = 0; i < N_maps; i++) {
    char** map = readMap(maps[i]);
    stat = game(map);
    if (stat != 'q') {
      char ans;
      cout << "\nYOU WON!!!\nEnter your name:\n";
      string name;
      cin >> name;
      if (name != "")
        writeRecords(name, stat);
      if (i == N_maps - 1) {
        cout << "You have finished all maps. CONGRATULATIONS!\n"
             << "Press any key. . .";
        getch();
        return 1;
      }
      cout << "Continue? (y/n)\n";
      cin >> ans;
      if (ans != 'y')
        return 'q';
    } else {
      return 'q';
    }
  }
  return 0;
}
