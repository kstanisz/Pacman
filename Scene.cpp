#include "Scene.h"

using namespace std;

Scene::Scene()
{
	labirynth = new int*[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++)
	{
		labirynth[i] = new int[MAP_SIZE];
	}
	readLabirynthFromFile();
}

void Scene::displayLabirynth()
{
	GLfloat wallDiffuse[] = { 0.0, 0.5, 0.25, 1.0 };
	GLfloat floorDiffuse[] = { 0.0, 2.5, 3.25, 1.0 };

	glPushMatrix();
	glTranslatef(TRANSLATION_X, 0.0,TRANSLATION_Z);
	
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (labirynth[i][j] == 1)
			{
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_DIFFUSE, wallDiffuse);
					glTranslatef(j*WALL_BRICK_SIZE, 0.0, i*WALL_BRICK_SIZE);
					glutSolidCube(WALL_BRICK_SIZE);
				glPopMatrix();
			}
			else
			{
			}
			glPushMatrix();
				glMaterialfv(GL_FRONT, GL_DIFFUSE, floorDiffuse);
				glTranslatef(j*WALL_BRICK_SIZE, -0.25, i*WALL_BRICK_SIZE);
			glutSolidCube(WALL_BRICK_SIZE);
			glPopMatrix();
		}
	}
	glPopMatrix();
}

void Scene::readLabirynthFromFile()
{
	ifstream file("labirynth.txt");
	if (file.is_open())
	{
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < MAP_SIZE; j++)
			{
				file >> labirynth[i][j];
			}
		}
	}
	file.close();
}
