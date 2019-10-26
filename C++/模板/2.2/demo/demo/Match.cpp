#include"pch.h"
#include"Time.h"
#include <iostream>

using namespace std;
void Match::printTime(Time &t)
{
	cout << t.m_iHour << "-" << t.m_iMin << "-" << t.m_iSec << endl;
}