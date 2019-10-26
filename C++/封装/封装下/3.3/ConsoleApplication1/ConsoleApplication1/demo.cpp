#include "pch.h"
#include <iostream>
#include"Array.h"

using namespace std;
int main()
{
	Array arr1(5);

	Array arr2(arr1);

	arr1.printArr();
	arr2.printArr();


	return 0;;
}

