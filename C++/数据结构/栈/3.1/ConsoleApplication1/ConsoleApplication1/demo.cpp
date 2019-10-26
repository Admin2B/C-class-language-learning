﻿#include "pch.h"
#include <iostream>
#include "MyStack.h"

using namespace std;
int main()
{
	MyStack *p = new MyStack(5);

	p->push((Coordinate(1, 2)));
	p->push((Coordinate(3, 4)));

	p->stackTraverse(true);
	p->stackTraverse(false);




	cout << p->stackLength() << endl;




	if (p->stackEmpty())
	{
		cout << "空" << endl;
	}

	if (p->stackFull())
	{
		cout << "满" << endl;
	}



	delete p;
	p = NULL;

    return 0; 
}




