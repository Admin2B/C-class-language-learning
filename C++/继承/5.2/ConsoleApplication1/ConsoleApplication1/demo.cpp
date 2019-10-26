#include "pch.h"
#include <iostream>
#include"Infantry.h"
using namespace std; 

void test1(Person p)
{
	p.play();
}

void test2(Person &p)
{
	p.play();
}

void test3(Person *p)
{
	p->play();
}
int main()
{
	Infantry infantry;
	test1(infantry);
	test2(infantry);
	test3(&infantry);
    return 0; 
}
