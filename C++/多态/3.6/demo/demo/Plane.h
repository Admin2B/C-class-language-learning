#ifndef PLANE_H
#define PLANE_H

#include<string>
#include "Flyable.h"

using namespace std;

class Plane 
{
public:
	Plane(string name);
	//virtual void takeoff();
	//virtual void land();
	void printCode();
private:
	string m_strCode;
};


#endif

