#include "pch.h"
#include <iostream>
#include"Coordinate.h"

using namespace std;

int main()
{
	Coordinate coor1(1,5);
	Coordinate coor2(4,7);
	Coordinate coor3(0, 0);
	coor3 = coor1 + coor2;
	//cout << coor3.getX() << "," << coor3.getY() << endl;
	
	cout << coor3[0]<<endl;
	cout << coor3[1] << endl;







	return 0;
}

