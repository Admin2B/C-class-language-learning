#include "pch.h"
#include <iostream>
#include"Bird.h"
#include"Plane.h"

using namespace std;


void doSomething(Flyable *obj)
{
	cout << typeid(*obj).name() << endl;
	obj->takeoff();
	if (typeid(*obj) == typeid(Bird))
	{
		Bird *bird = dynamic_cast<Bird *>(obj);
		bird->foraging();
	}
	if (typeid(*obj) == typeid(Plane))
	{
		Plane *plane = dynamic_cast<Plane *>(obj);
		plane->carry();
	}
	obj->land();
}
int main()
{
	Flyable *p = new Bird();
	Bird *b = dynamic_cast<Bird *>p;

	//cout << typeid(p).name() << endl;
	//cout << typeid(*p).name() << endl;
	//int i = 0;
	//cout << typeid(i).name() << endl;
	//Plane b;
	//doSomething(&b);
    return 0; 
}
 