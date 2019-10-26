#include "pch.h"
#include "Vector3.h"
#include "Matrix3x3.h"
#include <iostream>
//https://www.bilibili.com/video/av49151459/?p=6
using namespace std;

void print_v(Vector3 v)
{
	cout << "[" << v.x << "," << v.y << "," << v.z << "]" << endl;
}

void print_m(Matrix3x3 m)
{
	cout << m.m11 << "\t" << m.m12 << "\t" << m.m13 << endl;
	cout << m.m21 << "\t" << m.m22 << "\t" << m.m23 << endl;
	cout << m.m31 << "\t" << m.m32 << "\t" << m.m33 << endl;

}

int main()
{
	cout << "hello matrix !" << endl;
	Matrix3x3 a, b,c;
	a.m11 = 1; a.m12 = -5; a.m13 = 3;
	a.m21 = 0; a.m22 = -2; a.m23 = 6;
	a.m31 = 7; a.m32 =  2; a.m33 = -4;

	b.m11 = -8; b.m12 = 6; b.m13 = 1;
	b.m21 = 7; b.m22 = 0; b.m23 = -3;
	b.m31 = 2; b.m32 = 4; b.m33 = 5;

	cout << "矩阵第一次计算" << endl;
	c = a * b;
	print_m(c);
	cout << "矩阵第二次计算" << endl;
	a *= b;
	print_m(a);

	Vector3 v(3, -1, 4);
	Matrix3x3 m;
	m.m11 = -2; m.m12 = 0; m.m13 = 3;
	m.m21 = 5; m.m22 = 7; m.m23 = -6;
	m.m31 = 1; m.m32 = -4; m.m33 = 2;

	cout << "向量第一次计算" << endl;
	Vector3 r = v * m;
	print_v(r);

	cout << "第二次计算" << endl;
	v *= m;
	print_v(v);
}


