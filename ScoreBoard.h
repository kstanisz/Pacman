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
	const GLfloat scoreColor[3] = { 1.0,0.0,1.0 };
	const GLfloat livesColor[3] = { 1.0,0.0,1.0 };

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
