#include"pch.h"
#include<iostream>
#include"MigrantWorker.h"
using namespace std;

MigrantWorker::MigrantWorker(string name, string code) :Farmer(name), Worker(code)
{
	cout << "MigrantWorker" << endl;
}

MigrantWorker::~MigrantWorker()
{
	cout << "~MigrantWorker()" << endl;
}
