#include "pch.h"
#include <iostream>
#include"Circle.h"
#include"Rect.h"

using namespace std;

int main(void)
{
	Shape *shape1 = new Rect(3, 6);
	Shape *shape2 = new Circle(5);

	shape1->calcArea();
	shape2->calcArea();

	delete shape1;
	delete shape2;
	shape1 = NULL;
	shape2 = NULL;
    return 0; 
}

