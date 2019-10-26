#ifndef EULERANGLES_H
#define EULERANGLES_H
#include "Matrix4x3.h"
#include "RotationMatrix.h"
class Quaternion;

class EulerAngles
{
public:
	float heading;
	float pitch;
	float bank;
	EulerAngles() {}

	EulerAngles(float h, float p, float b) :heading(h), pitch(p), bank(b) {}

	void canonize();

	void fromObjectToWorldMatrix(const Matrix4x3 &m);
	void fromWorldToObjectMatrix(const Matrix4x3 &m);
	void fromRotationMatrix(const RotationMatrix &m);

	void fromObjectToInertialQuaternion(const Quaternion &q);
	void fromInertialToObjectQuaternion(const Quaternion &q);
};



#endif
