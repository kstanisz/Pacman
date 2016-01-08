#ifndef SOLIDCUBE_H
#define SOLIDCUBE_H

#define VERTICES 48
#define TEX_COORDS 32
#define CUBE_INDICES 24

#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "SOIL.h"
#include "Config.h"

class SolidCube
{
private:

	static GLfloat vertices[VERTICES];
	static GLfloat texCoords[TEX_COORDS];
	static GLubyte cubeIndices[CUBE_INDICES];

public:
	static void APIENTRY drawCube(GLuint texture);
};

#endif