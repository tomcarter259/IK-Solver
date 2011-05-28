#include "Vector3D.h"
#include "Point3D.h"

Vector3D::Vector3D(void):x(0.0), y(0.0), z(0.0)
{}

Vector3D::Vector3D(double a):x(a), y(a), z(a)
{}

Vector3D::Vector3D(double x, double y, double z):x(x), y(y), z(z)
{}

Vector3D::Vector3D(const Point3D& a):x(a.x), y(a.y), z(a.z)
{}

Vector3D::Vector3D(const Point3D& x, const Point3D& t):x(x.x - t.x), y(x.y - t.y), z(x.z - t.z)
{}

Vector3D::~Vector3D(void)
{}

// assignment of a vector: u = v
Vector3D& Vector3D::operator= (const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;

	return (*this);
}

// length: ||u||
double Vector3D::length(void)
{
	return sqrt(x*x + y*y + z*z);
}

//length squared: ||u||^2
double Vector3D::lengthSquared(void)
{
	return x*x + y*y + z*z;
}

//plus equals of two vectors: u += v
Vector3D& Vector3D::operator+= (const Vector3D& v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;

	return (*this);
}

//normalise a vector
void Vector3D::normalise(void)
{
	double l = sqrt(x*x + y*y + z*z);

	x = x / l;
	y = y / l;
	z = z / l;
}
