#ifndef SCENE_H
#define SCENE_H

#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "SOIL.h"
#include "Pellet.h"
#include "SolidCube.h"
#include "Config.h"

class Scene
{
private:

	int** labirynth;

public:

	Scene();
	~Scene();

	void displayLabirynth(GLuint textures[TEXTURES]);
	void readLabirynthFromFile();
};

#endif
