#ifndef  QUATERNION_H
#define  QUATERNION_H
#include "Vector3.h"
#include "MathUtil.h"
class RotationMatrix;
class EulerAngles;
class Quaternion
{
public:
	float w, x, y, z;
	void identity()
	{
		w = 1.0f;
		x = y = z = 0.0f;
	}

	void setToRotationAboutX(float theta);
	void setToRotationAboutY(float theta);
	void setToRotationAboutZ(float theta);
	void setToRotationAboutAxis(const Vector3 &axis,float theta);

	float getRotationAngle() const;
	Vector3 getRotationAxis() const;

	Quaternion operator *(const Quaternion &a) const;
	Quaternion &operator *=(const Quaternion &a);

	void normalize();
	void fromRotationMatrix(const RotationMatrix &m);

	void setToRotationObjectToInertial(const EulerAngles &orientation);
	void setToRotationInertialToObject(const EulerAngles &orientation);

};

extern const Quaternion kQuaternionIdentity;
extern float dotProduct(const Quaternion &a, const Quaternion &b);
extern Quaternion conjugate(const Quaternion &q);
extern Quaternion pow(const Quaternion &q, float exponent);

extern Quaternion slerp(const Quaternion &q0, const Quaternion &q1,float t);

#endif