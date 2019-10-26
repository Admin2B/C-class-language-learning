
#include "pch.h"
#include <iostream>
union data
{
	int a;
	char b;
	int c;
};
int main()
{
	union data data_1;
	data_1.b = 'C';
	data_1.a = 10;
    return 0; 
}


