#include "pch.h"
#include <iostream>
#include"Array.h"

using namespace std;

Array::Array(int len)
{
	this->len = len;
}

Array::~Array()
{

}

void Array::setLen(int len)
{
	this->len = len;
}

int Array::getLen()
{
	return len;
}

void Array::printInfo()
{

}