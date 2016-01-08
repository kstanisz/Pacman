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
	drawText("Score: "+intToString(score), 10, 10, scoreColor);
}

void ScoreBoard::displayLives(int lives)
{
	this->lives = lives;
	drawText("Lives: "+intToString(lives), 200, 10, scoreColor);
}

string ScoreBoard::intToString(int value)
{
	ostringstream ss;
	ss << value;
	return ss.str();
}