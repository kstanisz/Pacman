#include "Ghost.h"

#include<vector>
#include <cstdlib>
#include <ctime>

using namespace std;

Ghost::Ghost(int* positionOnMap) : Figure(positionOnMap)
{

}

void Ghost::display()
{
	GLfloat pacManDiffuse[] = { 0.3, 0.0, 0.3, 1.0 };

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_DIFFUSE, pacManDiffuse);
	glTranslatef(positionOnScene[Dimension(X)], positionOnScene[Dimension(Y)], positionOnScene[Dimension(Z)]);
	glutSolidSphere(0.25, 50, 50);
	glPopMatrix();
}

void Ghost::move()
{
	vector<Direction> possibleDirections;
	srand(time(NULL));

	switch (direction)
	{
	case Direction(FORWARD):
		if (stateVertical == 0)
		{
			if (map[positionOnMap[0] - 1][positionOnMap[1]] == 0)
				possibleDirections.push_back(Direction(FORWARD));
			if (map[positionOnMap[0]][positionOnMap[1]+1] == 0)
				possibleDirections.push_back(Direction(RIGHT));
			if (map[positionOnMap[0]][positionOnMap[1] - 1] == 0)
				possibleDirections.push_back(Direction(LEFT));

			int index = rand() % possibleDirections.size();

		}
		else
		{
			moveForward();
		}
		break;
	case Direction(BACK):
		if (stateVertical == 0)
		{
			if (map[positionOnMap[0] + 1][positionOnMap[1]] == 0)
				possibleDirections.push_back(Direction(BACK));
			if (map[positionOnMap[0]][positionOnMap[1] + 1] == 0)
				possibleDirections.push_back(Direction(RIGHT));
			if (map[positionOnMap[0]][positionOnMap[1] - 1] == 0)
				possibleDirections.push_back(Direction(LEFT));
		}
		else
		{
			moveBack();
		}
		break;
	case Direction(RIGHT):
		if (stateHorizontal == 0)
		{
			if (map[positionOnMap[0] - 1][positionOnMap[1]] == 0)
				possibleDirections.push_back(Direction(FORWARD));
			if (map[positionOnMap[0] + 1][positionOnMap[1]] == 0)
				possibleDirections.push_back(Direction(BACK));
			if (map[positionOnMap[0]][positionOnMap[1] + 1] == 0)
				possibleDirections.push_back(Direction(RIGHT));
		}
		else
		{
			moveRight();
		}
		break;
	case Direction(LEFT):
		if (stateHorizontal == 0)
		{
			if (map[positionOnMap[0] - 1][positionOnMap[1]] == 0)
				possibleDirections.push_back(Direction(FORWARD));
			if (map[positionOnMap[0] + 1][positionOnMap[1]] == 0)
				possibleDirections.push_back(Direction(BACK));
			if (map[positionOnMap[0]][positionOnMap[1] - 1] == 0)
				possibleDirections.push_back(Direction(LEFT));
		}
		else
		{
			moveLeft();
		}
		break;
	}
}
