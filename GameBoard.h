#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "SOIL.h"
#include "Pellet.h"
#include "SolidCube.h"
#include "Config.h"

class GameBoard
{
private:

	int** labirynth;

public:

	GameBoard();
	~GameBoard();

	void displayLabirynth(GLuint textures[TEXTURES]);
	void displaySkyBox(GLuint texture);
	void readLabirynthFromFile();
};

#endif
