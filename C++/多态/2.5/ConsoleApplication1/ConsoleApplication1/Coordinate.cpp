#include"pch.h"
#include<iostream>
#include"Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	cout << "Corrdinate" << endl;
	m_iX = x;
	m_iY = y;

}

Coordinate::~Coordinate()
{
	cout << "~Coordinate" << endl;
}