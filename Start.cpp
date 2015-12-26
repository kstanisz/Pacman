#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"
#include "Scene.cpp"
#include "PacMan.cpp"

using namespace std;

static Scene* scene = new Scene();
int** Figure::map = Figure::createMap();
PacMan* pacMan;

void init()
{
	GLfloat mat_ambient[] = { 1.0, 1.0,  1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0,  1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 10.0, 1.0 };
	GLfloat lm_ambient[] = { 0.2, 0.2,  0.2, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm_ambient);

	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
}

void reshape(GLsizei weight, GLsizei height)
{
	float* pacManPosition = pacMan->getPosition();

	if (height > 0 && weight > 0)
	{
		glViewport(0, 0, weight, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(60.0f, (float)weight / (float)height, 1.0f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(pacManPosition[Dimension(X)], CAMERA_Y, pacManPosition[Dimension(Z)] + CAMERA_Z,
			pacManPosition[Dimension(X)], pacManPosition[Dimension(Y)], pacManPosition[Dimension(Z)],
			0.0f, 1.0f, 0.0f);
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	scene->displayLabirynth();
	pacMan->display();
	glFlush();
	glutSwapBuffers();
}


void processMoveKeys(int key, int xx, int yy)
{
	switch (key)
	{

	case GLUT_KEY_UP:
		pacMan->moveForward();
		break;
	case GLUT_KEY_DOWN:
		pacMan->moveBack();
		break;
	case GLUT_KEY_RIGHT:
		pacMan->moveRight();
		break;
	case GLUT_KEY_LEFT:
		pacMan->moveLeft();
		break;
	}
	reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	display();
}

void initFigures()
{
	int* positionOnMap = new int[2];
	positionOnMap[0] = 22;
	positionOnMap[1] = 6;

	pacMan = new PacMan(positionOnMap);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_POSITION, WINDOW_POSITION);
	glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);

	glutCreateWindow("PAC-MAN");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(processMoveKeys);
	//glutIdleFunc(display);

	initFigures();

	init();
	glutMainLoop();

	return 0;
}