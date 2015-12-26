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

public:

	Figure(int* positionOnMap);

	void setPosition(float* positionOnScene);
	float* getPosition();
	
	void moveForward();
	void moveBack();
	void moveRight();
	void moveLeft();

	static int** createMap();

	virtual void display() = 0;
};

#endif

