#include "PacMan.h"

PacMan::PacMan(int* positionOnMap) : Figure(positionOnMap)
{
	command = Direction(FORWARD);
}

void PacMan::setCommand(int command)
{
	this->command = command;
}
void PacMan::moveControl()
{
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

void PacMan::display()
{
	GLfloat pacManDiffuse[] = { 0.9, 0.0, 0.9, 1.0 };

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pacManDiffuse);
		glTranslatef(positionOnScene[Dimension(X)], positionOnScene[Dimension(Y)], positionOnScene[Dimension(Z)]);
		glutSolidSphere(0.25, 50, 50);
	glPopMatrix();
}