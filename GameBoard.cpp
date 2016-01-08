#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard()
{
	labirynth = new int*[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++)
		labirynth[i] = new int[MAP_SIZE];

	readLabirynthFromFile();
}

GameBoard::~GameBoard()
{
	for (int i = 0; i < MAP_SIZE; i++)
		delete[] labirynth[i];
}

void GameBoard::displayLabirynth(GLuint textures[TEXTURES])
{
	GLfloat floorDiffuse[] = { 0.0, 2.5, 3.25, 1.0 };

	glPushMatrix();
		glTranslatef(TRANSLATION_X, 0.0,TRANSLATION_Z);
		Pellet*** map = Pellet::getMap();
	
		for (int i = 0; i < MAP_SIZE; i++)
			for (int j = 0; j < MAP_SIZE; j++)
			{
				if (labirynth[i][j] == 1)
				{
					glPushMatrix();
						glTranslatef(j*WALL_BRICK_SIZE, 0.0, i*WALL_BRICK_SIZE);
						SolidCube::drawCube(WALL_BRICK_SIZE, textures[0]);
					glPopMatrix();
				}
				else if(map[i][j]!=NULL)
					map[i][j]->display();
				
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_DIFFUSE, floorDiffuse);
					glTranslatef(j*WALL_BRICK_SIZE, -0.25, i*WALL_BRICK_SIZE);
					SolidCube::drawCube(WALL_BRICK_SIZE, textures[1]);
				glPopMatrix();
			}
	glPopMatrix();
}

void GameBoard::readLabirynthFromFile()
{
	ifstream file("labirynth.txt");
	if (file.is_open())
	{
		for (int i = 0; i < MAP_SIZE; i++)
			for (int j = 0; j < MAP_SIZE; j++)
				file >> labirynth[i][j];
			
	}
	file.close();
}


