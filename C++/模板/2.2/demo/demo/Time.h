#ifndef TIME_H
#define TIME_H

#include<iostream>
#include"Match.h"
//class Match;   error
using namespace std;

class Time
{
	friend void Match::printTime(Time &t);
public:
	Time(int hour ,int min,int sec);
private:
	int m_iHour;
	int m_iMin;
	int m_iSec;
};


#endif