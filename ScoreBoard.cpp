#include "ScoreBoard.h"
#include <iostream>
using namespace std;

ScoreBoard::ScoreBoard(){}

void ScoreBoard::drawText(string text, int x, int y,const GLfloat color[3])
{
	glColor3f(color[0], color[1], color[2]);	
	glRasterPos2i(x, y);

	for (std::string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}

	glColor3f(1.0f, 1.0f, 1.0f);
}

void ScoreBoard::displayScore(int score)
{
	this->score = score;
	drawText("SCORE: "+intToString(score), 30, SCOREBOARD_HEIGHT/2-9, greenColor);
}

void ScoreBoard::displayLives(int lives)
{
	this->lives = lives;
	drawText("LIVES: "+intToString(lives), 170, SCOREBOARD_HEIGHT/2-9, redColor);
}

void ScoreBoard::displayGameOverText()
{
	drawText("!!! GAME OVER !!!", 300, SCOREBOARD_HEIGHT / 2 - 9, redColor);
}

void ScoreBoard::displayWinnerText()
{
	drawText("..:: CONGRATULATIONS, YOU WIN! ::..", 300, SCOREBOARD_HEIGHT / 2 - 9, redColor);
}

void ScoreBoard::displayPauseInfo(bool pause)
{
	if (pause)
	{
		drawText("..:: Press Spacebar to START ::..", 300, SCOREBOARD_HEIGHT / 2 - 9, greenColor);
	}
	else
	{
		drawText("..:: Press Spacebar to PAUSE ::..", 300, SCOREBOARD_HEIGHT / 2 - 9, greenColor);
	}
}

string ScoreBoard::intToString(int value)
{
	ostringstream ss;
	ss << value;
	return ss.str();
}