#include "Pellet.h"

using namespace std;

Pellet::Pellet(){}

Pellet::Pellet(PelletType type, int* positionOnMap)
{
	this->type = type;
	this->positionOnMap = positionOnMap;
}

void Pellet::display()
{
	GLfloat pelletDiffuse[] = { 0.2, 0.0, 0.2, 1.0 };
	switch (type)
	{
	case PelletType(NORMAL):
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pelletDiffuse);
		glTranslatef(positionOnMap[1] * WALL_BRICK_SIZE, 0.1 / 2, positionOnMap[0] * WALL_BRICK_SIZE);
		glutSolidSphere(0.1, 50, 50);
		glPopMatrix();
		break;

	case PelletType(EXTRA):
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pelletDiffuse);
		glTranslatef(positionOnMap[1] * WALL_BRICK_SIZE, 0.1 / 2, positionOnMap[0] * WALL_BRICK_SIZE);
		glutSolidSphere(0.1, 50, 50);
		glPopMatrix();

		break;
	case PelletType(POWER):
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pelletDiffuse);
		glTranslatef(positionOnMap[1] * WALL_BRICK_SIZE, 0.1 / 2, positionOnMap[0] * WALL_BRICK_SIZE);
		glutSolidSphere(0.1, 50, 50);
		glPopMatrix();

		break;
	}
}

Pellet*** Pellet::createMap()
{
	Pellet*** map = new Pellet**[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++)
	{
		map[i] = new Pellet*[MAP_SIZE];
	}

	ifstream file("pellets.txt");
	if (file.is_open())
	{
		for (int i = 0; i < MAP_SIZE; i++)
		{
			for (int j = 0; j < MAP_SIZE; j++)
			{
				int* positionOnMap = new int[2];
				positionOnMap[0] = i;
				positionOnMap[1] = j;

				int value;
				file >> value;

				switch (value)
				{
				case PelletType(NO_PELLET):
					map[i][j] = NULL;
					break;

				case PelletType(NORMAL):
					map[i][j] = new Pellet(PelletType(NORMAL),positionOnMap);
					break;

				case PelletType(EXTRA):
					map[i][j] = new Pellet(PelletType(EXTRA),positionOnMap);
					break;

				case PelletType(POWER):
					map[i][j] = new Pellet(PelletType(POWER),positionOnMap);
					break;
				}
			}
		}
	}
	file.close();
	return map;
}

Pellet*** Pellet::getMap()
{
	return map;
}

bool Pellet::removePelletFromMap(int* positionOnMap)
{
	if (map[positionOnMap[0]][positionOnMap[1]] != NULL)
	{
		map[positionOnMap[0]][positionOnMap[1]] = NULL;
		return true;
	}

	return false;
}