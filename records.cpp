#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>

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
