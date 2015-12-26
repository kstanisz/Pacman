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

	Figure(int* positionOnMap);
	~Figure();

	void setPosition(float* positionOnScene);
	float* getPosition();
	
	void move(Direction direction);

	static int** createMap();

	virtual void display() = 0;
};

#endif

