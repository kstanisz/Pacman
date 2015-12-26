#include "PacMan.h"

PacMan::PacMan(int* positionOnMap) : Figure(positionOnMap)
{
}

void PacMan::display()
{
	GLfloat pacManDiffuse[] = { 0.9, 0.0, 0.9, 1.0 };

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pacManDiffuse);
		glTranslatef(positionOnScene[Dimension(X)], positionOnScene[Dimension(Y)], positionOnScene[Dimension(Z)]);
		glutSolidSphere(0.25, 50, 50);
	glPopMatrix();
}