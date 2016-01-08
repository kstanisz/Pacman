#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(){}

void ScoreBoard::drawText(string text, int x, int y,const GLfloat color[3])
{
	glColor3f(color[0], color[1], color[2]);
	glRasterPos2i(x, y);
	void * font = GLUT_BITMAP_9_BY_15;

	for (std::string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}
}

void ScoreBoard::displayScore(int score)
{
	this->score = score;
	drawText("Score: "+intToString(score), 30, SCOREBOARD_HEIGHT/2-9, scoreColor);
}

void ScoreBoard::displayLives(int lives)
{
	this->lives = lives;
	drawText("Lives: "+intToString(lives), 200, SCOREBOARD_HEIGHT/2-9, scoreColor);
}

void ScoreBoard::displayGameOverText()
{
	drawText("GAME OVER!", 350, SCOREBOARD_HEIGHT / 2 - 9, scoreColor);
}

void ScoreBoard::displayWinnerText()
{
	drawText("CONGRATULATION! YOU WIN!", 350, SCOREBOARD_HEIGHT / 2 - 9, scoreColor);
}

void ScoreBoard::displayPauseInfo(bool pause)
{
	if (pause)
	{
		drawText("Press Spacebar to START", 350, SCOREBOARD_HEIGHT / 2 - 9, scoreColor);
	}
	else
	{
		drawText("Press Spacebar to PAUSE", 350, SCOREBOARD_HEIGHT / 2 - 9, scoreColor);
	}
}

string ScoreBoard::intToString(int value)
{
	ostringstream ss;
	ss << value;
	return ss.str();
}