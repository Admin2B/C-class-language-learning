#include "pch.h"
#include "Vector3.h"
#include "Matrix4x3.h"
#include "MathUtil.h"
#include "RotationMatrix.h"
#include "EulerAngles.h"
#include <iostream>
#include "EditTriMesh.h"
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

class Line3D
{
public:
	Vector3 origin;
	Vector3 end;
};
class Ray3D
{
public:
	Vector3 rayOrigin;
	Vector3 rayDelta;
};
class Sphere
{
public:
	Vector3 center;
	float radius;
};

Vector3 computeBestFitNormal(const Vector3 v[], int n)
{
	Vector3 result = kZeroVector;
	const Vector3 *p = &v[n - 1];
	for (int i = 0; i < n; ++i)
	{
		const Vector3 *c = &v[i];
		result.x += (p->z + c->z)*(p->y - c->y);
		result.y += (p->x + c->x)*(p->z - c->z);
		result.z += (p->y + c->y)*(p->x - c->x);
		p = c;

	}
	result.normalize();
	return result;
}


bool isConvex(int n, const Vector3 v1[])
{
	float angleSum = 0.0f;
	for (int i = 0; i < n; ++i)
	{
		Vector3 e1;
		if (i == 0)
		{
			e1 = v1[n - 1] - v1[i];
		}
		else
		{
			e1 = v1[i - 1] - v1[i];
		}
		Vector3 e2;
		if (i == n - 1)
		{
			e2 = v1[0] - v1[i];
		}
		else
		{
			e2 = v1[i + 1] - v1[i];
		}
		e1.normalize();
		e2.normalize();
		float dot = e1 * e2;
		float theta = safeAcos(dot);
		angleSum += theta;
	}
	float convexAngleSum = (float)(n - 2)*kPi;
	if (angleSum < convexAngleSum - (float)n*0.0001f)
	{
		return false;
	}
	else
	{
		return true;
	}

}

int classifySpherePlane(const Vector3 &planeNormal, float planeD, const Vector3 &sphereCenter, float sphereRadius)
{
	float d = planeNormal * sphereCenter - planeD;
	if (d >= sphereRadius)
	{
		return 1;
	}
	if (d <= sphereRadius)
	{
		return -1;
	}
	return 0;
}

//class Vertex
//{
//	Vector3 p;
//
//};
//class Triangle
//{
//	Vertex ver[3];
//};
//
//class TriangleMesh
//{
//	int vertexCount;
//	Vertex *vertexList;
//	int triCount;
//	Triangle *triList;
//};

int main()
{
	cout << "hello" << endl;
	EditTriMesh mesh;
	mesh.addTri();
	mesh.addVertex();




	//system("pause");
}


