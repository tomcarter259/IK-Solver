#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include <math.h>

class Point3D;

class Vector3D
{
public:
	double x, y, z;

	Vector3D(void);

	Vector3D(double a);

	Vector3D(double x, double y, double z);

	Vector3D(const Point3D& a);

	// constructor from 2 points
	Vector3D(const Point3D& x, const Point3D& t);

	~Vector3D(void);

	// assignment of a vector: u = v
	Vector3D& operator= (const Vector3D& v);

	// length: ||u||
	double length(void);

	// length squared: ||u||^2
	double lengthSquared(void);

	// plus equals of two vectors: u += v
	Vector3D& operator+= (const Vector3D& v);

	//normalise a vector
	void normalise(void);

protected:

private:

};

//subtraction of two vectors: u - v
inline const Vector3D operator- (const Vector3D& u, const Vector3D& v)
{
	return Vector3D(u.x - v.x, u.y - v.y, u.z - v.z);
}

//dot product of two vectors: u . v
inline const double operator* (const Vector3D& u, const Vector3D& v)
{
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

//cross product of two vectors: u x v
inline const Vector3D operator^ (const Vector3D& u, const Vector3D& v)
{
	return Vector3D(u.y * v.z - u.z * v.y, 
					u.z * v.x - u.x * v.z,
					u.x * v.y - u.y * v.x);
}

#endif