#include "World.h"

using namespace std;

World::World(void):target(), bones(), error()
{}

World::~World(void)
{}

void World::build(void)
{
	//TODO: read in input file & set initial values here
	initGraphics();

	reset();
}

void World::reset(void)
{
	elbow = false;
	bones.clear();
	/*
	// root bone
	Bone root;
	root.origin = Point3D(0.0, 0.0, 0.0);
	root.addToAnglez(90.0);
	root.tip = calculateBoneTip(root.origin, root.getAngle());
	bones.push_back(root);

	Bone mid;
	mid.origin = root.tip;
	mid.addToAngle(0.0);
	mid.tip = calculateBoneTip(mid.origin, mid.getAngle());
	bones.push_back(mid);

	// end bone
	Bone end;
	end.origin = mid.tip;
	root.addToAngle(0.0);
	end.tip = calculateBoneTip(end.origin, end.getAngle());
	bones.push_back(end);

	// set initial target
	target.x = 2.0;
	target.y = -1.0;
	*/
}

void World::addBone(void)
{
	Bone newbie;
	newbie.origin = bones.back().tip;
	newbie.addToAngle(0.0);
	newbie.tip = calculateBoneTip(newbie.origin, newbie.getAngle());
	bones.push_back(newbie);
}

void World::removeBone(void)
{
	if(bones.size() > 1)
		bones.pop_back();
}

void World::run(void)
{
	// Event loop
    while (events())
    {
		//calculateBoneNormals();
		drawGraphics();
		/*
		calculateError();
		//printf("\n");
		//debugMessage("error", error.x, error.y);
		gradients.clear();

		for(unsigned int i = 0; i < bones.size(); i++)
		{
			//debugMessage("bone", i);
			Vector2D toTip = calculateToTip(bones[i].origin);

			Vector2D a = calculate2DMovement(toTip);
			//debugMessage("mVector", a.x, a.y);

			double gradient = a * error;
			//debugMessage("gradient", gradient);

			gradients.push_back(gradient);
		}

		//debugMessage("limb size", bones.size());

		// now iterate through and move the bones
		for(unsigned int k = 1; k <= bones.size(); k++)
		{
			int i = bones.size() - k;
			//debugMessage("HERRO", i);
			rotateJoint(i);

			if(i < (bones.size() - 1))
			{
				for(unsigned int j = i + 1; j < bones.size(); j++)
				{
					Vector2D shift;
					shift = bones[j].origin - bones[j-1].tip;

					bones[j].origin.x = bones[j].origin.x - shift.x;
					bones[j].origin.y = bones[j].origin.y - shift.y;
					bones[j].tip.x = bones[j].tip.x - shift.x;
					bones[j].tip.y = bones[j].tip.y - shift.y;
				}
			}
		}
		/*
		// now iterate through and move the bones
		for(unsigned int i = 0; i < bones.size(); i++)
		{
			if(i != 0)
			{
				Vector2D shift;
				shift.x = bones[i].origin.x - bones[i-1].tip.x;
				shift.y = bones[i].origin.y - bones[i-1].tip.y;

				bones[i].origin.x = bones[i].origin.x - shift.x;
				bones[i].origin.y = bones[i].origin.y - shift.y;
				bones[i].tip.x = bones[i].tip.x - shift.x;
				bones[i].tip.y = bones[i].tip.y - shift.y;
			}

			rotateJoint(i);
			debugMessage("origin", bones[i].origin.x, bones[i].origin.y);
			debugMessage("tip", bones[i].tip.x, bones[i].tip.y);
		}
		*/
    }
}

// initialise the graphics
void World::initGraphics()
{
    const int width = 800, height = 600;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) exit(1);

    // Window Settings
    SDL_WM_SetCaption("SDL/OpenGL Sample", "SDL/OpenGL Sample");

    // Get Video Info
    const SDL_VideoInfo *video = SDL_GetVideoInfo();
    if (!video) { SDL_Quit(); exit(2); }

    // Create Video Surface
    SDL_Surface *screen = SDL_SetVideoMode(width, height, video->vfmt->BitsPerPixel, SDL_OPENGL);
    if (!screen) { SDL_Quit(); exit(3); }

    // Size OpenGL to Video Surface
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    // Set Pixel Format
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // OpenGL Render Settings
    glClearColor(0, 0, 0, 1);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}

// Handle events
bool World::events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            // Exit commands
            if (event.key.keysym.sym == SDLK_ESCAPE) return false;
			if (event.key.keysym.sym == SDLK_q) return false;

			// Manually move target
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				target.x -= 1;
				return true;
			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				target.x += 1;
				return true;
			}
			if (event.key.keysym.sym == SDLK_UP)
			{
				target.y += 1;
				return true;
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				target.y -= 1;
				return true;
			}

			// Special commands
			if (event.key.keysym.sym == SDLK_e)
			{
				if(elbow == false)
					elbow = true;
				else
					elbow = false;
				return true;
			}
			if (event.key.keysym.sym == SDLK_a)
			{
				addBone();
				return true;
			}
			if (event.key.keysym.sym == SDLK_s)
			{
				removeBone();
				return true;
			}
			if (event.key.keysym.sym == SDLK_r)
			{
				reset();
				return true;
			}

			// Pre-set targets
			
			if (event.key.keysym.sym == SDLK_z)
			{
				target.x = 1;
				target.y = 2;
				return true;
			}
			if (event.key.keysym.sym == SDLK_x)
			{
				target.x = 5;
				target.y = 1;
				return true;
			}
			if (event.key.keysym.sym == SDLK_c)
			{
				target.x = -5;
				target.y = 1.5;
				return true;
			}
			if (event.key.keysym.sym == SDLK_v)
			{
				target.x = 5;
				target.y = -3;
				return true;
			}
			if (event.key.keysym.sym == SDLK_b)
			{
				target.x = 1;
				target.y = 1;
				return true;
			}
			if (event.key.keysym.sym == SDLK_n)
			{
				target.x = -3;
				target.y = -3;
				return true;
			}
			if (event.key.keysym.sym == SDLK_m)
			{
				target.x = -1;
				target.y = -1;
				return true;
			}
            break;

        case SDL_QUIT:
            return false;
        }
    }
    return true;
}

void World::drawGraphics()
{
	// materials
	GLfloat red_diffuse[]   = {1.0, 0.0, 0.0, 1.0};
	GLfloat green_diffuse[]   = {0.0, 1.0, 0.0, 1.0};
	GLfloat blue_diffuse[]   = {0.0, 0.0, 1.0, 1.0};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set location in front of camera
    glLoadIdentity();
    glTranslated(0, 0, -10);
	//glRotatef(270.0, 1.0, 0.0, 0.0);

	glEnable(GL_LIGHT0);


	glutSolidSphere(0.15, 50,50);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCone(0.15, 1, 16, 16);


	/*
	// draw the target
	glTranslated(target.x, target.y, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red_diffuse);
	glutSolidSphere(0.25, 50,50);
	glTranslated(-target.x, -target.y, 0);
	
	// draw the bones and joints
	// any translations or rotations are undone after drawing the object to return to neutral position
	// rotations must be undone in reverse order
	for(unsigned int i = 0; i < bones.size(); i++)
	{
		// origin joint
		glTranslated(bones[i].origin.x, bones[i].origin.y, bones[i].origin.z);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue_diffuse);
		glutSolidSphere(0.25, 50,50);

		// bone
		glRotatef(bones[i].getAnglex(), 1.0, 0.0, 0.0);
		glRotatef(bones[i].getAngley(), 0.0, 1.0, 1.0);
		glRotatef(bones[i].getAnglez(), 0.0, 0.0, 1.0);
		glutSolidCone(0.15, 1, 16, 16);
		glRotatef(-bones[i].getAnglez(), 0.0, 0.0, 1.0);
		glRotatef(-bones[i].getAngley(), 0.0, 1.0, 1.0);
		glRotatef(-bones[i].getAnglex(), 1.0, 0.0, 0.0);

		glTranslated(-bones[i].origin.x, -bones[i].origin.y, -bones[i].origin.z);

	}
	*/

	/*
	glutSolidSphere(0.15, 50,50);
	glTranslated(0,1.0,0);
	glutSolidSphere(0.15, 50,50);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glutSolidCone(0.15, 1, 16, 16);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	glTranslated(0,-1.0,0);
	glRotatef(270.0, 1.0, 0.0, 0.0);
	glutSolidCone(0.15, 1, 16, 16);
	glRotatef(-270.0, 1.0, 0.0, 0.0);
	*/
	/*
	// draw the bones and joints
	for(unsigned int i = 0; i < bones.size(); i++)
	{
		// origin point
		glBegin(GL_POINTS);
			glColor3d(1,0,0);
			glVertex3d(bones[i].origin.x, bones[i].origin.y, 0);
		glEnd();

		// origin joint
		glBegin(GL_TRIANGLE_FAN);
			glColor3d(0, 0, 1);
			glVertex3d(bones[i].origin.x, bones[i].origin.y, 0);
			for(double angle = 0; angle < 361; angle += 5)
			{
				double radius = 0.1;
				glVertex3d(bones[i].origin.x + sin(angle) * radius, bones[i].origin.y + cos(angle) * radius, 0);
			}
		glEnd();

		// tip point
		glBegin(GL_POINTS);
			glColor3d(1,0,0);
			glVertex3d(bones[i].tip.x, bones[i].tip.y, 0);
		glEnd();

		// tip joint
		glBegin(GL_TRIANGLE_FAN);
			glColor3d(0, 0, 1);
			glVertex3d(bones[i].tip.x, bones[i].tip.y, 0);
			for(double angle = 0; angle < 361; angle += 5)
			{
				double radius = 0.1;
				glVertex3d(bones[i].tip.x + sin(angle) * radius, bones[i].tip.y + cos(angle) * radius, 0);
			}
		glEnd();

		// bone
		glBegin(GL_TRIANGLES);
			glColor3d(0, 1, 0);
			glVertex3d(bones[i].origin.x + (bones[i].n.x * 0.05), bones[i].origin.y + (bones[i].n.y * 0.05), 0);
			glVertex3d(bones[i].origin.x + (bones[i].m.x * 0.05), bones[i].origin.y + (bones[i].m.y * 0.05), 0);
			glVertex3d(bones[i].tip.x, bones[i].tip.y, 0);
		glEnd();
				
	}

	// draw the target
	glBegin(GL_TRIANGLE_FAN);
		glColor3d(1, 0, 0);
		glVertex3d(target.x, target.y, 0);
		for(double angle = 0; angle < 361; angle += 5)
		{
			double radius = 0.1;
			glVertex3d(target.x + sin(angle) * radius, target.y + cos(angle) * radius, 0);
		}
	glEnd();
	*/

    // Show the frame
    SDL_GL_SwapBuffers();
}

Point2D World::calculateBoneTip(const Point2D origin, const double angle)
{
	double radius = 1.0;
	Point2D result;

	result.x = origin.x + radius * sind(angle);
	result.y = origin.y + radius * cosd(angle);

	return result;
}

void World::calculateError(void)
{
	error.x = target.x - getTip().x;
	error.y = target.y - getTip().y;
}

Vector2D World::calculateToTip(Point2D base)
{
	Vector2D result;

	result.x = getTip().x - base.x;
	result.y = getTip().y - base.y;

	return result;
}

Point2D World::getTip(void)
{
	Point2D tip;

	Bone b = bones.back();
	tip = b.tip;

	return tip;
}

Vector2D World::calculate2DMovement(Vector2D toTip)
{
	Vector3D axis(0.0, 0.0, 1.0);
	Vector3D t(toTip.x, toTip.y, 0);

	Vector3D cp = t ^ axis;

	// check we are only rotating on a 2D plane
	if(cp.z != 0)
		debugError("Rotation not in 2D", "z", cp.z);

	Vector2D result(cp.x, cp.y);
	
	return result;
}

void World::calculateBoneNormals(void)
{
	for(unsigned int i = 0; i < bones.size(); i++)
	{
		double bx = bones[i].tip.x - bones[i].origin.x;
		double by = bones[i].tip.y - bones[i].origin.y;

		bones[i].n.x = -by;
		bones[i].n.y = bx;
		bones[i].m.x = by;
		bones[i].m.y = -bx;
	}
}

double World::calculateAngleBetweenBones(int i)
{
	double angle = bones[i].getAngle() + (180 - bones[i-1].getAngle());
	
	return angle;
}

void World::rotateJoint(int i)
{
	//debugMessage("Rotating joint", i);
	double theta;

	theta = gradients[i];

	if(i != 0)
	{
		double bonesAngle = calculateAngleBetweenBones(i);
		
		if(bonesAngle > 0 && bonesAngle < 90)
		{
			if(theta < 0)
				theta = theta / 4;
			else if(theta > 0)
				theta = theta * 2;
		}

		if(bonesAngle > 270 && bonesAngle < 360)
		{
			if(theta > 0)
				theta = theta / 4;
			else if(theta < 0)
				theta = theta * 2;
		}

		if(bonesAngle > 180)
		{
			debugMessage(">180",1.0);
			if(elbow == true)
			{
				debugMessage("elbow true", 1.0);
				double excess = bonesAngle - 180;
				theta = 0 - excess;
			}
		}
	}

	bones[i].addToAngle(theta);
	//debugMessage("angle", bones[i].getAngle());

	bones[i].tip = calculateBoneTip(bones[i].origin, bones[i].getAngle());
}

void World::oldRotateJoint(int i)
{
	double ml, mx, my, alpha, beta, theta;

	//debugMessage("Rotating joint", i);

	// set degree to be rotated equal to the gradient
	theta = gradients[i];
	//debugMessage("theta", theta);

	// ml = length of vector from current tip location to new tip locations
	ml = 2 * sind(theta/2);
	//debugMessage("ml", ml);

	// alpha = angle between current bone position and vector from current tip to new tip
	alpha = 90 - (theta / 2);

	// beta = angle between vector from current tip to new tip and vertical
	beta = 90 - alpha;

	// my & mx = change in y and x required to move tip to new location
	my = ml * cosd(beta);
	//debugMessage("my", my);
	mx = ml * sind(beta);
	//debugMessage("mx", mx);

	// work out direction of rotation
	Vector2D b = bones[i].tip - bones[i].origin;
	
	if(b.x > 0)
	{
		if(b.y > 0)
		{
			bones[i].tip.x = bones[i].tip.x + mx;
			bones[i].tip.y = bones[i].tip.y - my;
		}
		else
		{
			bones[i].tip.x = bones[i].tip.x - mx;
			bones[i].tip.y = bones[i].tip.y - my;
		}
	}
	else if(b.x < 0)
	{
		if(b.y < 0)
		{
			bones[i].tip.x = bones[i].tip.x - mx;
			bones[i].tip.y = bones[i].tip.y + my;
		}
		else
		{
			bones[i].tip.x = bones[i].tip.x + mx;
			bones[i].tip.y = bones[i].tip.y + my;
		}
	}
	else
	{
		if(b.y > 0)
		{
			bones[i].tip.x = bones[i].tip.x + mx;
			bones[i].tip.y = bones[i].tip.y - my;
		}
		else if(b.y < 0)
		{
			bones[i].tip.x = bones[i].tip.x - mx;
			bones[i].tip.y = bones[i].tip.y + my;
		}
		else
			debugError("bone length is zero", "b.y", b.y);
	}

	double length = sqrt((bones[i].tip.x - bones[i].origin.x) * (bones[i].tip.x - bones[i].origin.x) + ((bones[i].tip.y - bones[i].origin.y) * (bones[i].tip.y - bones[i].origin.y)));
	debugMessage("length", length);
}
