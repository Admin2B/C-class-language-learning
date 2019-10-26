#ifndef AABB3_H
#define AABB3_H

#include "Vector3.h"
#include "Matrix4x3.h"
class AABB3
{
public:
	Vector3 min;
	Vector3 max;

	Vector3 size() const
	{
		return max - min;
	}

	float xSize()
	{
		return max.x - min.x;
	}
	float ySize()
	{
		return max.y - min.y;
	}
	float zSize()
	{
		return max.z - min.z;
	}

	Vector3 center()
	{
		return (max+min)*0.5f;
	}
	Vector3 corner(int i) const;
	void empty();
	bool isEmpty() const;
	void add(const Vector3 &p);
	void add(const AABB3 &box);
	bool contains(const Vector3 &p) const ;
	void setToTransformedBox(const AABB3 &box, const Matrix4x3 &m);
	Vector3 closestPointTo(const Vector3 &p) const;

	float rayIntersect(const Vector3 &rayOrg, const Vector3 &rayDelta, Vector3 *returnNormal = 0) const;

};


bool intersectAABBs(const AABB3 &box1, const AABB3 &box2, AABB3 *boxIntersect=0);

float intersectMovingAABB(const AABB3 &stationaryBox, const AABB3 &movingBox, const Vector3 &d);


#endif 
