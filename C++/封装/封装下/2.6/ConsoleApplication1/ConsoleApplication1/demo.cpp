#include "pch.h"
#include <iostream>
#include <string>
//#include"Coordinate.h"
#include"Line.h"
using namespace std;

int main()
{
	Line *p = new Line();
	delete p;
	p = NULL;

    return 0; 
}

