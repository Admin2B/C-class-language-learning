#include "pch.h"
#include <iostream>
#include "Soldier.h"

using namespace std;
int main(void)
{
	Soldier soldier;
	
	soldier.work();
	soldier.play(7);
	soldier.Person::play();
	
	return 0;
} 
