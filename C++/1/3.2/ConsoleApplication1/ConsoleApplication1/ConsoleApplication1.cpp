#include "pch.h"
#include <iostream>
using namespace std;

void fun(const int &a, const int &b);

int main()
{
	int x = 3;
	int y = 5;
	fun(x, y);
	cout << x <<","<< y << endl;

	//int const* p = &x;
	//cout << *p << endl;
	//p = &y;
	//cout << *p << endl;
	//*p = 10;
	/*int x = 3;
	int y = 5;
	int *const p = &x;
	*p = 10;*/
	//int x = 3;
	//int const *p = &x;//const int *p=&x;
	//x = 5;

    
	
}
void fun(const int &a, const int &b)
{
	a = 10;
	b = 20;
}

