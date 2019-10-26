#include "pch.h"
#include "MathUtil.h"

float wrapPi(float theta)
{
	theta += kPi;
	theta -= float(theta * k1Over2Pi)*k2Pi;
	theta -= kPi;
	return theta;
}