#include "pch.h"
#include <iostream>
#include"Time.h"
#include"Match.h"

using namespace std;


//void printTime(Time &t);

int main()
{
	Time t(6, 34, 25);
	Match m;
	m.printTime(t);
    return 0; 
}


//void printTime(Time &t)
//{
//	cout << t.m_iHour <<":"<< t.m_iMin <<":"<< t.m_iSec << endl;
//}