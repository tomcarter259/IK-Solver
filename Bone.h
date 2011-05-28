#ifndef _BONE_H_
#define _BONE_H_

#include "Utils.h"
#include "Point2D.h"
#include "Vector2D.h"

class Bone
{
public:
	Point2D origin, tip;
	Vector2D n, m;

	Bone(void);
	~Bone(void);

	void addToAngle(double a);

	double getAngle();

	void addToAnglex(double a);

	void addToAngley(double a);

	void addToAnglez(double a);

	double getAnglex();

	double getAngley();

	double getAnglez();

protected:

private:
	double angle;
	double anglex, angley, anglez;

};

#endif