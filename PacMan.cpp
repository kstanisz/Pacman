#include "PacMan.h"

PacMan::PacMan(int* positionOnMap) : Figure(positionOnMap)
{
	command = Direction(FORWARD);
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

void PacMan::collect()
{
	Pellet::removePelletFromMap(positionOnMap);
}

void PacMan::display()
{
	GLfloat pacManDiffuse[] = { 0.9, 0.0, 0.9, 1.0 };

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pacManDiffuse);
		glTranslatef(positionOnScene[Dimension(X)], positionOnScene[Dimension(Y)], positionOnScene[Dimension(Z)]);
		glutSolidSphere(0.25, 50, 50);
	glPopMatrix();
}