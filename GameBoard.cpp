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
						
						glTranslatef(j*WALL_BRICK_SIZE,-WALL_BRICK_SIZE/2, i*WALL_BRICK_SIZE);
						glScalef(WALL_BRICK_SIZE,WALL_BRICK_SIZE,WALL_BRICK_SIZE);
						SolidCube::drawCube(textures[0]);
					glPopMatrix();
				}
				else if(map[i][j]!=NULL)
					map[i][j]->display();
				
				glPushMatrix();
					glMaterialfv(GL_FRONT, GL_DIFFUSE, floorDiffuse);
					glTranslatef(j*WALL_BRICK_SIZE, -WALL_BRICK_SIZE, i*WALL_BRICK_SIZE);
					glScalef(WALL_BRICK_SIZE, WALL_BRICK_SIZE, WALL_BRICK_SIZE);
					SolidCube::drawCube(textures[1]);
				glPopMatrix();
			}
	glPopMatrix();
}

void GameBoard::displaySkyBox(GLuint texture)
{
	
	glDisable(GL_LIGHTING); 
	glDisable(GL_DEPTH_TEST);       
	glEnable(GL_TEXTURE_2D);     
	glBindTexture(GL_TEXTURE_2D, texture);

	glPushMatrix();
	glTranslatef(0.0f, 12.5f, 0.0f);

	glBegin(GL_QUADS);      
	glTexCoord2f(0, 0);      
	glVertex3f(SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);      
	glTexCoord2f(1, 0);   
	glVertex3f(-SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	//left face
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	//front face
	glTexCoord2f(1, 0);
	glVertex3f(SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(1, 1);
	glVertex3f(SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	//right face
	glTexCoord2f(0, 0);
	glVertex3f(SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(1, 0);
	glVertex3f(SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(1, 1);
	glVertex3f(SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);                      //top face
	glTexCoord2f(1, 0);
	glVertex3f(SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(1, 1);
	glVertex3f(SKYBOX_SIZE / 2, SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	//bottom face
	glTexCoord2f(1, 1);
	glVertex3f(SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, SKYBOX_SIZE / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glTexCoord2f(1, 0);
	glVertex3f(SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2, -SKYBOX_SIZE / 2);
	glEnd();

	glPopMatrix();
	glEnable(GL_LIGHTING);  //turn everything back, which we turned on, and turn everything off, which we have turned on.
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
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


