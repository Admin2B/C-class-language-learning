#include "pch.h"
#include <iostream>
#include "MyStack.h"

using namespace std;
int main()
{
	MyStack *p = new MyStack(5);

	p->push('h');
	p->push('e');
	p->push('l');
	p->push('l');
	p->push('o');

	p->stackTraverse(true);

	char elem = 0;
	p->pop(elem);

	cout  <<endl<<elem << endl;
	p->stackTraverse(true);

	//p->clearStack();


	cout << p->stackLength() << endl;



	//p->push('r');
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




