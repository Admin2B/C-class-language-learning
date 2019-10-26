#include "pch.h"
#include "Vector3.h"
#include "Matrix4x3.h"
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



void print_m(Matrix4x3 m)
{
	cout << to_zero(m.m11) << "\t" << to_zero(m.m12) << "\t" << to_zero(m.m13) << endl;
	cout << to_zero(m.m21) << "\t" << to_zero(m.m22) << "\t" << to_zero(m.m23) << endl;
	cout << to_zero(m.m31) << "\t" << to_zero(m.m32) << "\t" << to_zero(m.m33) << endl;

}

int main()
{
	cout << "hello 矩阵行列式!" << endl;

	Matrix4x3 m;
	m.m11 = -4; m.m12 = -3; m.m13 = 3;
	m.m21 = 0;  m.m22 = 2;  m.m23 = -2;
	m.m31 = 1;  m.m32 = 4;  m.m33 = -1;
	Matrix4x3 r = inverse(m);
	print_m(r);

	Matrix4x3 a = m * r;
	print_m(a);
}


