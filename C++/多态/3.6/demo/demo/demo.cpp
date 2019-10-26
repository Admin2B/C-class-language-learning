#include "pch.h"
#include <iostream>
#include"FighterPlane.h"

using namespace std;

void flyMatch(Plane *f1, Plane *f2)
{
	//f1->takeoff();
	//f1->land();
	//f2->takeoff();
	//f2->land();
	f1->printCode();
	f2->printCode();
}

int main()
{
	FighterPlane p1("001");
	FighterPlane p2("002");
	//p1.printCode();
	//p2.printCode();

	flyMatch(&p1, &p2);

    return 0; 
}
