#include <iostream>
#include <conio.h>

using namespace std;

int const n = 2;
int const m = 3;
void printLocation(char a[m][n])
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      cout << a[i][j];
    cout << "\n";
  }      
  return;
}
int main ()
{
  char a[m][n] = {{'#'}};
  printLocation(a);
  system("Pause");
  return 0;
}
