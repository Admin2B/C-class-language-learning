#include "pch.h"
#include <iostream>
#include "Worker.h"
using namespace std;
int main()
{
	Worker *p = new Worker();
	p->m_strName="Jim";
	p->m_iAge = 10;
	p->eat();
	p->m_iSalary = 1000;
	p->work();
	delete p;
	p = NULL;
	return 0;
}
