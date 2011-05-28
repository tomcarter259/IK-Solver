#ifndef _POINT2D_H_
#define _POINT2D_H_

class Point2D
{
public:
	double x, y;
	
	Point2D(void);

	Point2D(double a);

	Point2D(double x, double y);

	~Point2D(void);

	//assignment of a point: a = b
	Point2D& operator= (const Point2D& b);

protected:

private:

};

#endif