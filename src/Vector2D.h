#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "Utils.h"

class Point2D;

class Vector2D
{
public:
	double x, y;

	Vector2D(void);

	Vector2D(double a);

	Vector2D(double x, double y);

	Vector2D(const Point2D& a);

	// constructor from 2 points
	// when used for calculating F, target = x and tip = t
	Vector2D(const Point2D& x, const Point2D& t);

	~Vector2D(void);

	// assignment of a vector: u = v
	Vector2D& operator= (const Vector2D& v);

	// length: ||u||
	double length(void);

	// normalise a vector
	void normalise(void);

	// assign vector from 2 points
	void assignFromPoints(const Point2D& a, const Point2D& b);

protected:

private:

};

//subtraction of two vectors: u - v
inline const Vector2D operator- (const Vector2D& u, const Vector2D& v)
{
	return Vector2D(u.x - v.x, u.y - v.y);
}

// dot product of two vectors: u . v
inline const double operator* (const Vector2D& u, const Vector2D& v)
{
	return ((u.x * v.x) + (u.y * v.y));
}

// angle between two vectors
// returns the smallest angle in degrees
inline double angleBetweenVectors(Vector2D m, Vector2D n)
{
	double dp, ar, ad;

	m.normalise();
	
	n.normalise();
	//printf("---Test: n normalised = %Lf,%Lf\n", n.x, n.y);

	dp = n*m;

	//printf("---Test: dot product = %Lf\n", dp);

	ar = acos(dp);

	ad = convertRadiansToDegrees(ar);

	return ad;
}
	
#endif