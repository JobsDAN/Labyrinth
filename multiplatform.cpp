// Copyright 2015 JobsDAN

#ifndef CONIO_CPP
#define CONIO_CPP

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int _getch() {
  struct termios oldt, newt;
  int ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

void setlocale(int a, char* b) {
 return;
}

#endif
