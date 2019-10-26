#include "pch.h"
#include <iostream>

#include"MigrantWorker.h"

using namespace std;

int main()
{
	MigrantWorker *p = new MigrantWorker("Merry","200","yellow");
	p->Farmer::printColor();
	p->Worker::printColor();
	delete p;
	p = NULL;

    return 0; 
}
