#include <iostream>
#ifdef __linux__ 
	#include "conio_l.cpp"
#elif _WIN32
	#include <conio.h>
#endif

using namespace std;

int main()
{
	int a = getch();
	cout << a << endl;
	return 0;
}
