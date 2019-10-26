#include "pch.h"
#include "Vector3.h"
#include "Matrix3x3.h"
#include "MathUtil.h"
#include <iostream>
//https://www.bilibili.com/video/av49151459/?p=6
using namespace std;

float to_zero(float n)
{
	return ((abs(n)<0.00001) ? 0 : n);
}

void print_v(Vector3 v)
{
	cout << "[" << to_zero(v.x) << "," 
		<< to_zero(v.y) << ","
		<< to_zero(v.z) << "]" << endl;
}



void print_m(Matrix3x3 m)
{
	cout << to_zero(m.m11) << "\t" << to_zero(m.m12) << "\t" << to_zero(m.m13) << endl;
	cout << to_zero(m.m21) << "\t" << to_zero(m.m22) << "\t" << to_zero(m.m23) << endl;
	cout << to_zero(m.m31) << "\t" << to_zero(m.m32) << "\t" << to_zero(m.m33) << endl;

}

int main()
{
	cout << "hello 线性变换--旋转 !" << endl;
	Vector3 a(10, 0, 0),b;
	print_v(a);
	Matrix3x3 M;
	M.setRotate(3, kPiOver2);
	print_m(M);
	b = a * M;
	print_v(b);
	
	M.setRotate(3,kPi);
	print_m(M);
	b = a * M;
	print_v(b);

	M.setRotate(1, -22 / 180.0f * kPi);
	print_m(M);


	M.setRotate(2, 30 / 180.0f * kPi);
	print_m(M);

}


