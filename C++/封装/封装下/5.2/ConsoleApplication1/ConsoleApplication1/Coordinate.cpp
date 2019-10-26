#include "pch.h"
#include<iostream>
#include"Coordinate.h"

using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
	
}
Coordinate::~Coordinate()
{
	
}
void Coordinate::setX(int x)
{
	m_iX = x;
}
int Coordinate::getX() const
{
	return m_iX;
}
void Coordinate::setY(int y)
{
	m_iY = y;
}
int Coordinate::getY() const
{
	return m_iY;
}