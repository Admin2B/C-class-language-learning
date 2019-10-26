#include "pch.h"
#include <iostream>
#include "Soldier.h"

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



int main(void)
{
	Person p;
	Soldier s;
	test3(&p);
	test3(&s);

	system("pause");
	return 0;
} 

