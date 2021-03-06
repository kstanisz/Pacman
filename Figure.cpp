#include "Figure.h"

using namespace std;

int** Figure::map = Figure::createMap();

Figure::Figure()
{
}

Figure::Figure(int* positionOnMap)
{
	setPositionOnMap(positionOnMap);
}

Figure::~Figure()
{
	delete positionOnMap;
	delete positionOnScene;
}

void Figure::setPositionOnScene(float* positionOnScene)
{
	this->positionOnScene = positionOnScene;
}

float* Figure::getPositionOnScene()
{
	return positionOnScene;
}

void Figure::setPositionOnMap(int* positionOnMap)
{
	this->positionOnMap = positionOnMap;
	stateHorizontal = 0;
	stateVertical = 0;
	direction = Direction(FORWARD);

	positionOnScene = new float[DIMENSIONS];
	positionOnScene[Dimension(X)] = float(positionOnMap[1]) * WALL_BRICK_SIZE + TRANSLATION_X;
	positionOnScene[Dimension(Y)] = float(0.25 / 2.0);
	positionOnScene[Dimension(Z)] = float(positionOnMap[0]) * WALL_BRICK_SIZE + TRANSLATION_Z;
}

int* Figure::getPositionOnMap()
{
	return positionOnMap;
}

int Figure::getStateHorizontal()
{
	return stateHorizontal;
}

int Figure::getStateVertical()
{
	return stateVertical;
}

void Figure::move(Direction direction)
{
	switch (direction)
	{
	case Direction(FORWARD):
	{
		if (stateHorizontal != 0)
			return;

		if ((stateVertical == 0 && map[positionOnMap[0] - 1][positionOnMap[1]] == 0) || stateVertical == 1 || stateVertical == 2)
		{
			stateVertical++;
			positionOnScene[Dimension(Z)] -= STEP;
		}
		else if (stateVertical == 3)
		{
			stateVertical = 0;
			positionOnMap[0]--;
			positionOnScene[Dimension(Z)] -= STEP;
		}

		break;
	}
	case Direction(BACK):
	{
		if(stateHorizontal != 0)
			return;

		if (stateVertical >= 1 && stateVertical <= 3)
		{
			stateVertical--;
			positionOnScene[Dimension(Z)] += STEP;
		}
		else if (stateVertical == 0 && map[positionOnMap[0] + 1][positionOnMap[1]] == 0)
		{
			stateVertical = 3;
			positionOnMap[0]++;
			positionOnScene[Dimension(Z)] += STEP;
		}

		break;
	}
	case Direction(RIGHT):
	{
		if (stateVertical != 0)
			return;

		if ((stateHorizontal == 0 && map[positionOnMap[0]][positionOnMap[1] + 1] == 0) || stateHorizontal == 1 || stateHorizontal == 2)
		{
			stateHorizontal++;
			positionOnScene[Dimension(X)] += STEP;
		}
		else if (stateHorizontal == 3)
		{
			stateHorizontal = 0;
			positionOnMap[1]++;
			positionOnScene[Dimension(X)] += STEP;
		}

		break;
	}
	case Direction(LEFT):
	{
		if (stateVertical != 0)
			return;

		if (stateHorizontal >= 1 && stateHorizontal <= 3)
		{
			stateHorizontal--;
			positionOnScene[Dimension(X)] -= STEP;
		}
		else if (stateHorizontal == 0 && map[positionOnMap[0]][positionOnMap[1] - 1] == 0)
		{
			stateHorizontal = 3;
			positionOnMap[1]--;
			positionOnScene[Dimension(X)] -= STEP;
		}

		break;
	}
	}
}

void Figure::display(GLuint texture)
{
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
}

int** Figure::createMap()
{
	int** map = new int*[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++)
	{
		map[i] = new int[MAP_SIZE];
	}

	ifstream file("labirynth.txt");
	if (file.is_open())
	{
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < MAP_SIZE; j++)
			{
				file >> map[i][j];
			}
		}
	}
	file.close();
	return map;
}


