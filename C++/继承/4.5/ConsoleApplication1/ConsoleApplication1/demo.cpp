#include "pch.h"
#include <iostream>
#include "Soldier.h"

using namespace std;

int main(void)
{
	Person *p=new Soldier;

	p->play();
	delete p;
	p = NULL;

	system("pause");
	return 0;
} 

