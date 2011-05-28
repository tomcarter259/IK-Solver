#ifndef _POINT3D_H_
#define _POINT3D_H_

class Point3D
{
public:
	double x, y, z;

	Point3D(void);

	Point3D(double a);

	Point3D(double x, double y, double z);

	~Point3D(void);

	// assignment of a point: a = b
	Point3D& operator= (const Point3D& b);
	
protected:

private:

};

#endif