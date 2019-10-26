﻿#include "pch.h"
#include <iostream>
using namespace std;

template <typename T>
void display(T a)
{
	cout << a << endl;
}


template <typename T,class S>
void display(T t,S s)
{
	cout << t << endl;
	cout << s << endl;
}



template <typename T, int Ksize>
void display(T a)
{
	for (int i = 0; i < Ksize; i++)
		cout << a << endl;
}



int main()
{
	//display<double>(10.89);
	//display<int,double>(5,8.3);
	display<int, 5>(6);
    return 0; 
}

