#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "Config.h"
#include "glut.h"
#include "Figure.cpp"

class PacMan : public Figure
{
private:

public:

	PacMan(int* positionOnMap) : Figure(positionOnMap)
	{
	}

	void display()
	{
		GLfloat pacManDiffuse[] = { 0.9, 0.0, 0.9, 1.0 };

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pacManDiffuse);
		glTranslatef(positionOnScene[Dimension(X)], positionOnScene[Dimension(Y)], positionOnScene[Dimension(Z)]);
		glutSolidSphere(0.25, 50, 50);
		glPopMatrix();
	}
};