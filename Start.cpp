#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"
#include "Scene.h"
#include "PacMan.h"
#include "Ghost.h"

using namespace std;

static Scene* scene = new Scene();
int** Figure::map = Figure::createMap();
PacMan* pacMan;
Ghost** ghosts;
bool life = true;

void init()
{
	cout << "xdddd";
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

void reshape(GLsizei width, GLsizei height)
{
	float* pacManPosition = pacMan->getPositionOnScene();

	if (height > 0 && width > 0)
	{
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(60.0f, (float)width / (float)height, 1.0f, 1000.0f);
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
	for (int i = 0; i < GHOSTS; i++)
	{
		ghosts[i]->display();
	}
	glFlush();
	glutSwapBuffers();
}


void processMoveKeys(int key, int xx, int yy)
{
	switch (key)
	{

	case GLUT_KEY_UP:
		pacMan->setCommand(Direction(FORWARD));
		break;
	case GLUT_KEY_DOWN:
		pacMan->setCommand(Direction(BACK));
		break;
	case GLUT_KEY_RIGHT:
		pacMan->setCommand(Direction(RIGHT));
		break;
	case GLUT_KEY_LEFT:
		pacMan->setCommand(Direction(LEFT));
		break;
	}
}

void game()
{
	if (life)
	{
		for (int i = 0; i < GHOSTS; i++)
		{
			ghosts[i]->randomMove();
		}

		pacMan->moveControl();
		if (pacMan->isCollision(ghosts))
			life = false;

		Sleep(35);
	}
	reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	display();
}

void initFigures()
{
	ghosts = new Ghost*[GHOSTS];
	int* positionOnMap = new int[2];
	
	positionOnMap[0] = 22;
	positionOnMap[1] = 6;
	pacMan = new PacMan(positionOnMap);

	positionOnMap = new int[2];
	positionOnMap[0] = 12;
	positionOnMap[1] = 11;
	ghosts[0] = new Ghost(positionOnMap);

	positionOnMap = new int[2];
	positionOnMap[0] = 12;
	positionOnMap[1] = 13;
	ghosts[1] = new Ghost(positionOnMap);

	positionOnMap = new int[2];
	positionOnMap[0] = 12;
	positionOnMap[1] = 16;
	ghosts[2] = new Ghost(positionOnMap);

	positionOnMap = new int[2];
	positionOnMap[0] = 13;
	positionOnMap[1] = 13;
	ghosts[3] = new Ghost(positionOnMap);
}

void deleteReferences()
{
	delete[] ghosts;
	delete pacMan;
	delete scene;
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
	glutIdleFunc(game);

	initFigures();

	init();
	glutMainLoop();

	deleteReferences();
	return 0;
}