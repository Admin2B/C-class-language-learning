#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

class Vector3
{
public:
	float x, y, z;
	Vector3() {}
	Vector3(const Vector3 &a) : x(a.x),y(a.y),z(a.z) {}
	Vector3(float nx,float ny,float nz) : x(nx),y(ny),z(nz) {}

	void zero() { x = y = z = 0.0f; }

	Vector3 operator -() const { return Vector3(-x, -y, -z); }
};

inline float vectorMag(const Vector3 &a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}


#endif