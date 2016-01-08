#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <windows.h>
#include <string>
#include <sstream>
#include <GL/gl.h>
#include "glut.h"
#include <tchar.h>
#include "Config.h"

using namespace std;

class ScoreBoard
{
private:

	int score = 0;
	int lives = 3;
	void * font = GLUT_BITMAP_HELVETICA_18;
	const GLfloat greenColor[3] = { 0.0f,0.3f,0.0f };
	const GLfloat redColor[3] = { 0.3f,0.0f,0.0f };


	void drawText(std::string text, int x, int y, const GLfloat color[3]);
	string intToString(int value);

public:
	ScoreBoard();
	void displayScore(int score);
	void displayLives(int lives);
	void displayGameOverText();
	void displayWinnerText();
	void displayPauseInfo(bool pause);
};

#endif
