#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "Figure.cpp"

class Ghost : public Figure
{
private:

public:

	Ghost(int* positionOnMap) : Figure(positionOnMap)
	{

	}

	void display()
	{

	}
};