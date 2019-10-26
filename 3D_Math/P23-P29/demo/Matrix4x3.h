#ifndef MATRIX4X3_H
#define MATRIX4X3_H
class Vector3;

class Matrix4x3
{
public:
	float m11, m12, m13;
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	void setRotate(int axis, float theta);
	//void setupScale(const float Kx, const float Ky, const float Kz);
	void setupScale(const Vector3 &s);
	void setupProject(const Vector3 &n);
	void setupReflect(int axis,float k);
	void setupReflect(const Vector3 &n);
	void setupShear(int axis, float s, float t);
	
	void zeroTranslation();
	void setTranslation(const Vector3 &d);
	void setupTranslation(const Vector3 &d);
	
};


Matrix4x3 operator *(const Matrix4x3 &a, const Matrix4x3 &b);
Vector3 operator *(const Vector3 &p, const Matrix4x3 &m);

Matrix4x3 &operator *=(Matrix4x3 &a, const Matrix4x3 &m);
Vector3 &operator *=(Vector3 &p, const Matrix4x3 &m);

float determinant(const Matrix4x3 &m);
Matrix4x3 inverse(const Matrix4x3 &m);

Vector3 getTranslation(const Matrix4x3 &m);





#endif