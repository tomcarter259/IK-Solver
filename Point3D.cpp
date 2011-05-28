#include "Point3D.h"

Point3D::Point3D(void):x(0.0), y(0.0), z(0.0)
{}

Point3D::Point3D(double a):x(a), y(a), z(a)
{}

Point3D::Point3D(double x, double y, double z):x(x), y(y), z(z)
{}

Point3D::~Point3D(void)
{}

//assignment of a point: a = b
Point3D& Point3D::operator= (const Point3D& b)
{
	x = b.x;
	y = b.y;
	z = b.z;

	return (*this);
}