#include "Point2D.h"

Point2D::Point2D(void):x(0.0), y(0.0)
{}

Point2D::Point2D(double a):x(a), y(a)
{}

Point2D::Point2D(double x, double y):x(x), y(y)
{}

Point2D::~Point2D(void)
{}

//assignment of a point: a = b
Point2D& Point2D::operator= (const Point2D& b)
{
	x = b.x;
	y = b.y;

	return (*this);
}