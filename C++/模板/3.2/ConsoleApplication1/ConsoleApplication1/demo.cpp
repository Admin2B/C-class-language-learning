#include "pch.h"
#include <iostream>
#include"Tank.h"
using namespace std;


int main()
{
	Tank *p = new Tank('A');
	cout << Tank::getCount() << endl;
	Tank *q = new Tank('B');
	cout << q->getCount() << endl;


	delete p;
	delete q;
	p = NULL;
	q = NULL;
	cout << Tank::getCount() << endl;
	//Tank t1('A');
	//cout << Tank::getCount() << endl;
	//cout << t1.getCount() << endl;
	
	return 0;
}

