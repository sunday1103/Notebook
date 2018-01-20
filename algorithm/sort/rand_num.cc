#include <cstdlib>
#include <iostream>
#include <time.h> 
#include <fstream>

using namespace std;
int main(int agrc ,char * agrv[])
{
	int n = 100;
	int max = 100;
	if (agrc != 1)
	{
		n = atoi(agrv[1]);
	}
	ofstream file("./input.txt");
	for (int i = 0; i < n; ++i)
	{
		std::srand(i);
		file<< rand() % max<<endl;
	}
	file<<"end";	
}