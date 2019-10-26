#include "pch.h"
#include "Quaternion.h"
#include<math.h>
#include <assert.h>
#include "RotationMatrix.h"
#include "EulerAngles.h"
const Quaternion kQuaternionIdentity = { 1.0f,0.0f,0.0f,0.0f };


void Quaternion::setToRotationAboutX(float theta)
{
	float thetaOver2 = theta * 0.5f;
	w = cos(thetaOver2);
	x = sin(thetaOver2);
	y = z = 0.0f;
		
}
void Quaternion::setToRotationAboutY(float theta)
{
	float thetaOver2 = theta * 0.5f;
	w = cos(thetaOver2);
	y = sin(thetaOver2);
	x = z = 0.0f;
}
void Quaternion::setToRotationAboutZ(float theta)
{
	float thetaOver2 = theta * 0.5f;
	w = cos(thetaOver2);
	z = sin(thetaOver2);
	y = x = 0.0f;

}

void Quaternion::setToRotationAboutAxis(const Vector3 &axis, float theta)
{
	assert(fabs(vectorMag(axis) - 1.0f) < 0.001f);

	float thetaOver2 = theta * 0.5f;
	float sinThetaOver2 = sin(thetaOver2);
	//float cosThetaOver2 = cos(thetaOver2);
	w = cos(thetaOver2);
	x = axis.x*sinThetaOver2;
	y = axis.y*sinThetaOver2;
	z = axis.z*sinThetaOver2;
}

float Quaternion::getRotationAngle() const
{
	float thetaOver2 = safeAcos(w);
	return thetaOver2 * 2.0f;
}

Vector3 Quaternion::getRotationAxis() const
{
	float sinThetaOver2Sq = 1.0f - w * w;
	float oneOverSinThetaOver2 = 1.0f / sqrt(sinThetaOver2Sq);
	return Vector3
	(x*oneOverSinThetaOver2,
	y*oneOverSinThetaOver2,
	z*oneOverSinThetaOver2);

}

Quaternion Quaternion::operator *(const Quaternion &a) const
{
	Quaternion result;
	result.w = w * a.w - x * a.x - y * a.y - z * a.z;
	result.x = w * a.x - x * a.w - z * a.y - y * a.z;
	result.y = w * a.y - y * a.w - x * a.z - z * a.x;
	result.z = w * a.z - z * a.w - y * a.x - x * a.y;
	return result;
}

Quaternion &Quaternion::operator *=(const Quaternion &a)
{
	*this = *this*a;
	return *this;
}

void Quaternion::normalize()
{
	float mag = (float)sqrt(w*w + x * x + y * y + z * z);
	if(mag>0.0f)
	{ 
		float oneOverMag = 1.0f / mag;
		w = w * oneOverMag;
		x = x * oneOverMag;
		y = y * oneOverMag;
		z = z * oneOverMag;
	}
	else
	{
		assert(false);
		identity();
	}
}

float dotProduct(const Quaternion &a, const Quaternion &b)
{
	return a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
}

Quaternion conjugate(const Quaternion &q)
{
	Quaternion result;
	
	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;

	return result;
}

Quaternion pow(const Quaternion &q, float exponent)
{
	if (fabs(q.w) > 0.9999f)
	{
		return q;
	}

	float alpha = acos(q.w);
	float newAlpha = exponent = exponent * alpha;
	Quaternion result;
	result.w = cos(newAlpha);

	float mult = sin(newAlpha) / sin(alpha);
	result.x = q.x*mult;
	result.y = q.y*mult;
	result.z = q.z*mult;
	return result;
}

void Quaternion::fromRotationMatrix(const RotationMatrix &m)
{
	float m11 = m.m11;
	float m12 = m.m12;
	float m13 = m.m13;

	float m21 = m.m21;
	float m22 = m.m22;
	float m23 = m.m23;

	float m31 = m.m31;
	float m32 = m.m32;
	float m33 = m.m33;

	float fourWSquaredMinus1 = m11 + m22 + m33;
	float fourXSquaredMinus1 = m11 - m22 - m33;
	float fourYSquaredMinus1 = m22 - m11 - m33;
	float fourZSquaredMinus1 = m33 - m11 - m22;

	int biggestIndex = 0;
	float fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	if (fourXSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}
	if (fourYSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}
	if (fourZSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}

	float biggestVal = sqrt(fourBiggestSquaredMinus1+1.0f)*0.5f;
	float mult = 0.25 / biggestVal;
	switch (biggestIndex)
	{
	case 0:
		w = biggestVal;
		x = (m23 - m32)*mult;
		y = (m31 - m13)*mult;
		z = (m12 - m21)*mult;
		break;
	case 1:
		x = biggestVal;
		w = (m23 - m32)*mult;
		y = (m12 + m21)*mult;
		z = (m31 + m13)*mult;
		break;
	case 2:
		y = biggestVal;
		w = (m31 - m13)*mult;
		x = (m12 + m21)*mult;
		z = (m23 + m32)*mult;
		break;
	case 3:
		z = biggestVal;
		w = (m12 - m21)*mult;
		x = (m31 + m13)*mult;
		y = (m23 + m32)*mult;
		break;
	}
}

void Quaternion::setToRotationObjectToInertial(const EulerAngles &orientation)
{
	float sp, sb, sh, cp, cb, ch;
	sinCos(&sp, &cp, orientation.pitch*0.5f);
	sinCos(&sb, &cb, orientation.bank*0.5f);
	sinCos(&sh, &ch, orientation.heading*0.5f);
	w = ch * cp*cb + sh * sp*sb;
	x = ch * sp*cb + sh * cp*sb;
	y = -ch * sp*sb + sh * cp*cb;
	z = -sh * sp*cb + ch * cp*sb;
}


void Quaternion::setToRotationInertialToObject(const EulerAngles &orientation)
{
	float sp, sb, sh, cp, cb, ch;
	sinCos(&sp, &cp, orientation.pitch*0.5f);
	sinCos(&sb, &cb, orientation.bank*0.5f);
	sinCos(&sh, &ch, orientation.heading*0.5f);
	w = ch * cp*cb + sh * sp*sb;
	x = -ch * sp*cb - sh * cp*sb;
	y = ch * sp*sb - sh * cp*cb;
	z = sh * sp*cb - ch * cp*sb;
}

Quaternion slerp(const Quaternion &q0, const Quaternion &q1, float t)
{
	if (t <= 0.0f)
		return q0;
	if (t > +1.0f)
		return q1;
	float cosOmega = dotProduct(q0, q1);
	float q1w = q1.w;
	float q1x = q1.x;
	float q1y = q1.y;
	float q1z = q1.z;
	if (cosOmega < 0.0f)
	{
		q1w = -q1.w;
		q1x = -q1.x;
		q1y = -q1.y;
		q1z = -q1.z;
		cosOmega = -cosOmega;
	}

	float k0, k1;
	if (cosOmega > 0.9999f)
	{
		k0 = 1.0f - t;
		k1 = t;
	}
	else
	{
		float sinOmega = sqrt(1 - cosOmega * cosOmega);
		float omega = atan2(sinOmega, cosOmega);
		float oneOverSinOmega = 1.0f / sinOmega;
		k0 = sin((1.0f - t)*omega)*oneOverSinOmega;
		k1 = sin(t*omega)*oneOverSinOmega;
	}

	Quaternion result;
	result.x = k0 * q0.x + k1 * q1x;
	result.y = k0 * q0.y + k1 * q1y;
	result.z = k0 * q0.z + k1 * q1z;
	result.w = k0 * q0.w + k1 * q1w;
	return result;
}