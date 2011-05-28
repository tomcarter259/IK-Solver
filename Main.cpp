#include <iostream>
#include <string>
#include <stdio.h>
#include <sdl.h>
#include <sdl_opengl.h>
#include <GL/glut.h>

#include "World.h"

using namespace std;

int main(int argc, char **argv)
{
	printf("Program start\n");

	World w;

	printf("Building world......");
	w.build();
	printf("World built\n");

	printf("Running simulation...\n");
	w.run();
	printf("Simulation finished\n");

	printf("Cleaning up.....");
    SDL_Quit();
	printf("done\n");

    return 0;
}