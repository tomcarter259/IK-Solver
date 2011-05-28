#include "Vector2D.h"
#include "Point2D.h"

Vector2D::Vector2D(void):x(0.0), y(0.0)
{}

Vector2D::Vector2D(double a):x(a), y(a)
{}

Vector2D::Vector2D(double x, double y):x(x), y(y)
{}

Vector2D::Vector2D(const Point2D& a):x(a.x), y(a.y)
{}

Vector2D::Vector2D(const Point2D& x, const Point2D& t):x(x.x - t.x), y(x.y - t.y)
{}

Vector2D::~Vector2D(void)
{}

// assignment of a vector: u = v
Vector2D& Vector2D::operator= (const Vector2D& v)
{
	x = v.x;
	y = v.y;

	return (*this);
}

// length: ||u||
double Vector2D::length(void)
{
	return sqrt(x*x + y*y);
}

// normalise a vector
void Vector2D::normalise(void)
{
	double l = sqrt(x*x + y*y);

	x = x / l;
	y = y / l;
}

// assign vector from 2 points
void Vector2D::assignFromPoints(const Point2D& a, const Point2D& b)
{
	x = a.x - b.x;
	y = a.y - b.y;
}