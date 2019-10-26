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

	Vector3 v5(-5, 0, 0.4);
	Vector3 v6 = v5 * -3;
	print_vector(v6);

	Vector3 v7(4.7, -6, 8);
	Vector3 v8 = v7 / 2;
	print_vector(v8);

	Vector3 v9(1, 2, 3);
	Vector3 v10 = 2*v9;
	print_vector(v10);

	Vector3 v11(12, -5, 0);
	v11.normalize();
	print_vector(v11);

	Vector3 a(1, 2, 3);
	Vector3 b(4, 5, 6);
	Vector3 c = a + b;
	print_vector(c);

	Vector3 d = b - a;
	print_vector(d);

	Vector3 x(5, 0, 0);
	Vector3 y(-1, 8, 0);
	float dd = distance(x, y);
	cout << dd << endl;
}


