#include "pch.h"
#include <iostream>
#include"Coordinate.h"

using namespace std;

int main()
{
	Coordinate coor1(3,5);
	cout << coor1.getX() <<","<<coor1.getY()<< endl;
	-coor1;
	cout << coor1.getX() << "," << coor1.getY() << endl;
	return 0;
}

