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

using namespace std;

void writeRecords (string name, int record)
{
  ofstream file("records.txt", ios_base::app);
  file << name << " " << record << "\n";
  return;
}  

void readRecords ()
{
  ifstream file("records.txt");
  string line;
  while (getline(file, line))
    cout << line << "\n";
  return;
}
