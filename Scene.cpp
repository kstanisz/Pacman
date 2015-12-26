#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"

using namespace std;

class Scene
{
private:

    int** labirynth;

public:

	Scene()
	{
		labirynth = new int*[MAP_SIZE];

		for (int i = 0; i < MAP_SIZE; i++)
		{
			labirynth[i] = new int[MAP_SIZE];
		}

		readLabirynthFromFile();
	}

	void displayLabirynth()
	{
		GLfloat wallDiffuse[] = { 0.0, 0.5, 0.25, 1.0 };
		GLfloat floorDiffuse[] = { 0.0, 2.5, 3.25, 1.0 };

		glPushMatrix();
			glTranslatef(-7.25, 0.0, -13.75);

			for (int i = 0; i < MAP_SIZE; i++)
			{
				for (int j = 0; j < MAP_SIZE; j++)
				{
					if (labirynth[i][j]==1)
					{
						glPushMatrix();
							glMaterialfv(GL_FRONT, GL_DIFFUSE, wallDiffuse);
							glTranslatef(j*0.5, 0.0, i*0.5);
							glutSolidCube(0.5);
						glPopMatrix();
					}
					else
					{

					}

					glPushMatrix();
						glMaterialfv(GL_FRONT, GL_DIFFUSE, floorDiffuse);
						glTranslatef(j*0.5, -0.25, i*0.5);
						glutSolidCube(0.5);
					glPopMatrix();
				}
			}
		glPopMatrix();
	}

	void readLabirynthFromFile()
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
};