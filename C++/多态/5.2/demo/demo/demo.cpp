#include "pch.h"
#include <iostream>
#include"IndexException.h"
#include<string>
using namespace std;

void test()
{
	throw IndexException();
}

int main()
{
	try
	{
		test();
	}
	catch (...)
	{
		cout << "Exception" << endl;
	}
	return 0;
}

