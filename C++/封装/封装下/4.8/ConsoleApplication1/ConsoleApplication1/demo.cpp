#include "pch.h"
#include <iostream>
#include "Array.h"
using namespace std;
int main()
{
	Array arr1(10);
	arr1.printInfo();
	cout << &arr1 << endl;
	//cout << "len=" << arr1.getLen() << endl;
	return 0;
}

