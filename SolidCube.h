#ifndef SOLIDCUBE_H
#define SOLIDCUBE_H

#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "SOIL.h"
#include "Config.h"

class SolidCube
{
public:
	static void APIENTRY drawCube(GLdouble size,GLuint texture);
};


#endif