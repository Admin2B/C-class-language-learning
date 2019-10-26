#include "pch.h"
#include "Vector3.h"
#include <iostream>
//https://www.bilibili.com/video/av49151459/?p=6
using namespace std;

void print_vector(Vector3 v)
{
	cout << "[" << v.x << "," << v.y << "," << v.z << "]" << endl;
}

int main()
{
    cout << "Hello World!\n"; 

	Vector3 v1(10, 20, 30);
	print_vector(v1);

	Vector3 v2(v1);
	print_vector(v2);

	Vector3 v3 = -v1;
	print_vector(v3);

	v2.zero();
	print_vector(v2);

	Vector3 v4(5, -4, 7);
	float r = vectorMag(v4);
	cout << r << endl;


}


