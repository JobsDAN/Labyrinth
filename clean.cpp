#include <iostream>
#ifdef __linux__
	#define WINDOWS 0
#elif _WIN32
	#define WINDOWS 1
#endif

void clean()
{
  if (WINDOWS)
		system("cls");
	else
		system("clear");
	return;
}
