#include "PacMan.h"


PacMan::PacMan() : Figure()
{
	openJaw = true;
	openCloseJawCounter = 0;
	score = 0;
}

PacMan::PacMan(int* positionOnMap) : Figure(positionOnMap)
{
	openJaw = true;
	openCloseJawCounter = 0;
	score = 0;
	command = Direction(FORWARD);
}

void PacMan::increaseOpenCloseJawCounter()
{
	if (openCloseJawCounter < 2)
		openCloseJawCounter++;
	else
	{
		openCloseJawCounter = 0;
		openJaw = openJaw ? false : true;
	}
}

void PacMan::setCommand(int command)
{
	this->command = command;
}

bool PacMan::isCollision(Ghost** ghosts)
{
	for (int i = 0; i < GHOSTS; i++)
	{
		int* ghostPosition = ghosts[i]->getPositionOnMap();
		// Sprawdzam czy jest kolizja u gory
		if (positionOnMap[1] == ghostPosition[1] && // Ta sama wartosc na x
			(positionOnMap[0] == ghostPosition[0] ||	// Ta sama wartosc na y
				(positionOnMap[0] == (ghostPosition[0] + 1) && stateVertical>ghosts[i]->getStateVertical()))) // Duszek wyzej o 1, ale nachodza na siebie
			return true;

		// Sprawdzam czy jest kolizja od dolu
		if (positionOnMap[1] == ghostPosition[1] && // Ta sama wartosc na x
			(positionOnMap[0] == ghostPosition[0] ||	// Ta sama wartosc na y
				(positionOnMap[0] == (ghostPosition[0]-1) && stateVertical<ghosts[i]->getStateVertical()))) // Duszek nizej o 1, ale nachodza na siebie
			return true;

		// Sprawdzam czy jest kolizja od prawej
		if (positionOnMap[0] == ghostPosition[0] && // Ta sama wartosc na y
			(positionOnMap[1] == ghostPosition[1] ||	// Ta sama wartosc na x
				(positionOnMap[1] == (ghostPosition[1] - 1) && stateHorizontal>ghosts[i]->getStateHorizontal()))) // Duszek jest po prawej o 1, ale nachodza na siebie
			return true;

		// Sprawdzam czy jest kolizja od lewej
		if (positionOnMap[0] == ghostPosition[0] && // Ta sama wartosc na y
			(positionOnMap[1] == ghostPosition[1] ||	// Ta sama wartosc na x
				(positionOnMap[1] == (ghostPosition[1] + 1) && stateHorizontal<ghosts[i]->getStateHorizontal()))) // Duszek jest po lewej o 1, ale nachodza na siebie
			return true;
	}
	return false;
}

void PacMan::moveControl()
{
	increaseOpenCloseJawCounter();

	if (stateVertical == 0 || stateHorizontal == 0)
		collect();

	switch (direction)
	{
	case Direction(FORWARD):
		if (stateVertical == 0 && command!=Direction(FORWARD))
		{
			if (command == Direction(BACK) && map[positionOnMap[0] + 1][positionOnMap[1]] == 0)
			{
				direction = Direction(BACK);
				move(Direction(BACK));
			}
			else if (command == Direction(RIGHT) && map[positionOnMap[0]][positionOnMap[1]+1] == 0)
			{
				direction = Direction(RIGHT);
				move(Direction(RIGHT));
			}
			else if (command == Direction(LEFT) && map[positionOnMap[0]][positionOnMap[1]-1] == 0)
			{
				direction = Direction(LEFT);
				move(Direction(LEFT));
			}
			else
			{
				move(Direction(FORWARD));
			}
		}
		else
		{
			move(Direction(FORWARD));
		}

		break;
	case Direction(BACK):
		if (stateVertical == 0 && command != Direction(BACK))
		{
			if (command == Direction(FORWARD) && map[positionOnMap[0] + -1][positionOnMap[1]] == 0)
			{
				direction = Direction(FORWARD);
				move(Direction(FORWARD));
			}
			else if (command == Direction(RIGHT) && map[positionOnMap[0]][positionOnMap[1] + 1] == 0)
			{
				direction = Direction(RIGHT);
				move(Direction(RIGHT));
			}
			else if (command == Direction(LEFT) && map[positionOnMap[0]][positionOnMap[1] - 1] == 0)
			{
				direction = Direction(LEFT);
				move(Direction(LEFT));
			}
			else
			{
				move(Direction(BACK));
			}
		}
		else
		{
			move(Direction(BACK));
		}

		break;
	case Direction(RIGHT):
		if (stateHorizontal == 0 && command != Direction(RIGHT))
		{
			if (command == Direction(FORWARD) && map[positionOnMap[0] + -1][positionOnMap[1]] == 0)
			{
				direction = Direction(FORWARD);
				move(Direction(FORWARD));
			}
			else if (command == Direction(BACK) && map[positionOnMap[0] + 1][positionOnMap[1]] == 0)
			{
				direction = Direction(BACK);
				move(Direction(BACK));
			}
			else if (command == Direction(LEFT) && map[positionOnMap[0]][positionOnMap[1] - 1] == 0)
			{
				direction = Direction(LEFT);
				move(Direction(LEFT));
			}
			else
			{
				move(Direction(RIGHT));
			}
		}
		else
		{
			move(Direction(RIGHT));
		}

		break;
	case Direction(LEFT):
		if (stateHorizontal == 0 && command != Direction(LEFT))
		{
			if (command == Direction(FORWARD) && map[positionOnMap[0] + -1][positionOnMap[1]] == 0)
			{
				direction = Direction(FORWARD);
				move(Direction(FORWARD));
			}
			else if (command == Direction(BACK) && map[positionOnMap[0] + 1][positionOnMap[1]] == 0)
			{
				direction = Direction(BACK);
				move(Direction(BACK));
			}
			else if (command == Direction(RIGHT) && map[positionOnMap[0]][positionOnMap[1] + 1] == 0)
			{
				direction = Direction(RIGHT);
				move(Direction(RIGHT));
			}
			else
			{
				move(Direction(LEFT));
			}
		}
		else
		{
			move(Direction(LEFT));
		}

		break;

	}
}

bool PacMan::isOpenJaw()
{
	return openJaw;
}

int PacMan::getScore()
{
	return score;
}

void PacMan::collect()
{
	score+=Pellet::collectPelletFromMap(positionOnMap);
}

void PacMan::display(GLuint texture)
{
	//glDisable(GL_LIGHTING);
	glPushMatrix();

		glTranslatef(positionOnScene[Dimension(X)], positionOnScene[Dimension(Y)], positionOnScene[Dimension(Z)]);
		glRotatef(90.0f*direction, 0.0f, 1.0f, 0.0f);
		glRotatef(-110.0f, 1.0f, 0.0f, 0.0f);

		GLUquadricObj *qObj = gluNewQuadric();	
		gluQuadricTexture(qObj, GL_TRUE);
		
		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture);
			gluSphere(qObj, 0.25f, 30, 30);
		glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	//glEnable(GL_LIGHTING);
}