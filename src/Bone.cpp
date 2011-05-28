#include "Bone.h"

Bone::Bone(void):origin(0.0), tip(0.0), n(0.0), m(0.0), angle(0.0)
{}

Bone::~Bone(void)
{}

void Bone::addToAngle(double a)
{
	angle += a;

	while(angle < 0)
		angle = 360 + angle;

	while(angle > 360)
		angle = angle - 360;
}

double Bone::getAngle()
{
	return angle;
}

void Bone::addToAnglex(double a)
{
	anglex += a;

	while(anglex < 0)
		anglex = 360 + anglex;

	while(anglex > 360)
		anglex = anglex - 360;
}

void Bone::addToAngley(double a)
{
	angley += a;

	while(angley < 0)
		angley = 360 + angley;

	while(angley > 360)
		angley = angley - 360;
}

void Bone::addToAnglez(double a)
{
	anglez += a;

	while(anglez < 0)
		anglez = 360 + anglez;

	while(anglez > 360)
		anglez = anglez - 360;
}

double Bone::getAnglex()
{
	return anglex;
}

double Bone::getAngley()
{
	return angley;
}

double Bone::getAnglez()
{
	return anglez;
}