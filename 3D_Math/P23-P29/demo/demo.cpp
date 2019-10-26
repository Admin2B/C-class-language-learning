#include "pch.h"
#include "Vector3.h"
#include "Matrix4x3.h"
#include "MathUtil.h"
#include "RotationMatrix.h"
#include "EulerAngles.h"
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
	cout << "hello " << endl;
	RotationMatrix m;
	//m.m11 = 0.866; m.m12 = 0.0f; m.m13 = -0.5f;
	//m.m21 = 0.0f;  m.m22 = 1.0f; m.m23 = 0.0f;
	//m.m31 = 0.5f;  m.m32 = 0.0f;  m.m33 = 0.866;

	m.setup(EulerAngles (30*kPi/180, 0, 0));




	Vector3 v(10, 20, 30);
	Vector3 v2;
	v2 = m.inertialToObject(v);
	print_v(v2);
	v2 = m.objectToInertial(v2);
	print_v(v2);
}


