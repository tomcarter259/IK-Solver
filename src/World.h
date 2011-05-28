#ifndef _WORLD_H_
#define _WORLD_H_

#include <sdl.h>
#include <sdl_opengl.h>
#include <GL/glut.h>

#include <math.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

#include "Point2D.h"
#include "Point3D.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Bone.h"
#include "Utils.h"
#include "Debug.h"

class World
{
public:
	World(void);
	~World(void);

	// set up the window, bones and target to start
	void build(void);

	// reset the bones and target to initial positions
	void reset(void);

	// add a bone to the limb
	void addBone(void);

	// sever a bone from the limb
	void removeBone(void);

	// run IK Solver Simulation
	void run(void);

	// initialise the graphics
	void initGraphics(void);

	// handle events
	bool events(void);

	// draw the scene
	void drawGraphics(void);

	// calculate bone tip location
	Point2D calculateBoneTip(const Point2D origin, const double angle);

	// calculate error vector (from tip to target)
	void calculateError(void);

	// calculate toTip vector (base of current bone to tip)
	Vector2D calculateToTip(Point2D base);

	// returns the location of the tip
	Point2D getTip(void);

	// calculate the 2D movement vector
	// this is the direction the tip would move if the joint in focus was rotated
	Vector2D calculate2DMovement(Vector2D toTip);

	// calculate normals to the bones (n and m)
	void calculateBoneNormals(void);

	// calculates the angle between the bone to be rotated and the previous bone
	double calculateAngleBetweenBones(int i);

	// rotate joint
	void rotateJoint(int i);

	// old way to srotate joint
	void oldRotateJoint(int i);

protected:

private:
	vector<Bone>		bones;
	vector<double>		gradients;
	Point2D				target;
	Vector2D			error;
	bool				elbow;
		
};

#endif