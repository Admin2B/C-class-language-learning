#include "pch.h"
#include "IndexException.h"
#include<iostream>
using namespace std;

void IndexException::printException()
{
	cout << "提示：数组越界！" << endl;
}