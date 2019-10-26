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
	cout << "hello 矩阵行列式!" << endl;

	Matrix3x3 m;
	m.m11 = 3;  m.m12 = -2; m.m13 = 0;
	m.m21 = 1;  m.m22 = 4;  m.m23 = -3;
	m.m31 = -1; m.m32 = 0;  m.m33 = 2;

	float detM = determinant(m);
	cout << detM << endl;
}


