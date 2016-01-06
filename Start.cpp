#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"
#include "Scene.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Pellet.h"
#include "SolidCube.h"

using namespace std;

Scene* scene;
PacMan* pacMan;
Ghost** ghosts;
int** Figure::map = Figure::createMap();
Pellet*** Pellet::map = Pellet::createMap();
GLuint textures[TEXTURES];
int lifes=LIFES;
int oldTime=0;

void display();
void reshape(GLsizei width, GLsizei height);
void setCamera();
void processMoveKeys(int key, int xx, int yy);
void idle();
void game(int passedTime);
void setStartPositions();
void init();
void initFigures();
int LoadGlTextures();
void deleteReferences();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_POSITION, WINDOW_POSITION);
	glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);

	glutCreateWindow("PAC-MANa");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(processMoveKeys);
	glutIdleFunc(idle);

	init();
	glutMainLoop();

	deleteReferences();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	scene->displayLabirynth(textures);
	pacMan->display(textures[2+ (pacMan->isOpenJaw()? 0:1)]);
	for (int i = 0; i < GHOSTS; i++)
		ghosts[i]->display();
	
	glFlush();
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height> 0 && width > 0)
	{
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(60.0f, (float)width / (float)height, 1.0f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		setCamera();
	}
}

void setCamera()
{
	float* pacManPosition = pacMan->getPositionOnScene();

	gluLookAt(pacManPosition[Dimension(X)], CAMERA_Y, pacManPosition[Dimension(Z)] + CAMERA_Z,
		pacManPosition[Dimension(X)], pacManPosition[Dimension(Y)], pacManPosition[Dimension(Z)],
		0.0f, 1.0f, 0.0f);
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

void idle()
{
	int elapsedTime = glutGet(GLUT_ELAPSED_TIME);
	int passedTime = elapsedTime - oldTime;
	oldTime = elapsedTime;
	game(passedTime);
	reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	glutPostRedisplay();
}

void game(int passedTime)
{
	if (passedTime <= DISPLAY_TIME)
		Sleep(DISPLAY_TIME - passedTime);

	if (lifes>0)
	{
		for (int i = 0; i < GHOSTS; i++)
			ghosts[i]->randomMove();

		pacMan->moveControl();
		if (pacMan->isCollision(ghosts))
		{
			lifes--;
			Sleep(RESPAWN_TIME);
			setStartPositions();
		}
	}
	else
	{
		//cout << pacMan->getScore() << endl;
	}
}

void setStartPositions()
{
	int* pacManPositionOnMap = new int[2];
	pacManPositionOnMap[0] = 22;
	pacManPositionOnMap[1] = 6;
	pacMan->setPositionOnMap(pacManPositionOnMap);
	pacMan->setCommand(Direction(FORWARD));

	int** ghostPositionOnMap = new int*[GHOSTS];
	for (int i = 0; i < GHOSTS; i++)
		ghostPositionOnMap[i] = new int[2];

	ghostPositionOnMap[0][0] = 12;
	ghostPositionOnMap[0][1] = 11;
	ghosts[0]->setPositionOnMap(ghostPositionOnMap[0]);

	ghostPositionOnMap[1][0] = 12;
	ghostPositionOnMap[1][1] = 13;
	ghosts[1]->setPositionOnMap(ghostPositionOnMap[1]);

	ghostPositionOnMap[2][0] = 12;
	ghostPositionOnMap[2][1] = 16;
	ghosts[2]->setPositionOnMap(ghostPositionOnMap[2]);

	ghostPositionOnMap[3][0] = 13;
	ghostPositionOnMap[3][1] = 13;
	ghosts[3]->setPositionOnMap(ghostPositionOnMap[3]);
}

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
	
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	scene = new Scene();
	initFigures();
	LoadGlTextures();
}

void initFigures()
{
	pacMan = new PacMan();
	ghosts = new Ghost*[GHOSTS];
	for (int i = 0; i < GHOSTS; i++)
		ghosts[i] = new Ghost();

	setStartPositions();
}

int LoadGlTextures()
{
	string fileName[] = { "Textures/grass.bmp", "Textures/soil.bmp","Textures/pacmanOpen.bmp","Textures/pacmanClose.bmp"};
	
	for (int i = 0; i < TEXTURES; i++)
	{
		textures[i] = SOIL_load_OGL_texture(
			fileName[i].c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

		if (textures[i] == 0)
			return false;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	return true;
}

void deleteReferences()
{
	delete[] ghosts;
	delete pacMan;
	delete scene;
}

