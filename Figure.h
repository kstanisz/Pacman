#ifndef FIGURE_H
#define FIGURE_H

#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"

class Figure
{
protected:

	float* positionOnScene;
	int* positionOnMap;
	static int** map;
	int stateHorizontal;
	int stateVertical;
	int direction;

public:

	Figure();
	Figure(int* positionOnMap);
	~Figure();

	void setPositionOnScene(float* positionOnScene);
	float* getPositionOnScene();
	void setPositionOnMap(int* positionOnMap);
	int* getPositionOnMap();
	int getStateHorizontal();
	int getStateVertical();
	
	void move(Direction direction);

	static int** createMap();

	void display(GLuint texture);
};

#endif

