#ifndef COORDINATE_H
#define COORDIANTE_H


#include <iostream>

using namespace std;

class Coordinate
{
	friend ostream &operator <<(ostream &out, Coordinate &coor);
public:
	Coordinate(int x=0,int y=0);
	bool operator ==(Coordinate &coor);
	void printCoordinate();
private:
	int m_iX;
	int m_iY;

};



#endif
