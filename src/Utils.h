#ifndef _UTILS_H_
#define _UTILS_H_

#include <math.h>

// convert radians to degrees
inline double convertRadiansToDegrees(const double r)
{
	double d = r * 180 / 3.14159265358979323;

	return d;
}

// returns the sine of angle x in degrees
inline double sind(const double x)
{
	return sin(x * 3.14159265 / 180);
}

// returns the cosine of angle x in degrees
inline double cosd(const double x)
{
	return cos(x * 3.14159265 / 180);
}

#endif