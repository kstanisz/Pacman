#include "Pellet.h"

using namespace std;

int Pellet::numberOfPellets = 0;
Pellet*** Pellet::map = NULL;

Pellet::Pellet()
{

}

Pellet::Pellet(PelletType type, int* positionOnMap)
{
	this->type = type;
	this->positionOnMap = positionOnMap;

	switch (type)
	{
	case PelletType(NORMAL):
		value = NORMAL_PELLET_VALUE;
		break;
	case PelletType(EXTRA):
		value = EXTRA_PELLET_VALUE;
		break;
	case PelletType(POWER):
		value = POWER_PELLET_VALUE;
		break;
	}
}

int Pellet::getValue()
{
	return value;
}

void Pellet::display()
{
	GLfloat pelletNormalDiffuse[] = { 0.2f, 0.0f, 0.2f, 1.0f };
	GLfloat pelletExtraDiffuse[] = { 0.2f, 0.4f, 0.2f, 1.0f };
	GLfloat pelletPowerDiffuse[] = { 0.8f, 0.1f, 0.8f, 1.0f};
	switch (type)
	{
	case PelletType(NORMAL):
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pelletNormalDiffuse);
		glTranslatef(positionOnMap[1] * WALL_BRICK_SIZE, 0.1 / 2, positionOnMap[0] * WALL_BRICK_SIZE);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();
		break;

	case PelletType(EXTRA):
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pelletExtraDiffuse);
		glTranslatef(positionOnMap[1] * WALL_BRICK_SIZE, 0.1 / 2, positionOnMap[0] * WALL_BRICK_SIZE);
		glutSolidSphere(0.1, 8, 8);
		glPopMatrix();

		break;
	case PelletType(POWER):
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, pelletPowerDiffuse);
		glTranslatef(positionOnMap[1] * WALL_BRICK_SIZE, 0.1 / 2, positionOnMap[0] * WALL_BRICK_SIZE);
		glutSolidTeapot(0.1);
		glPopMatrix();

		break;
	}
}

void Pellet::createMap()
{
	Pellet::numberOfPellets = 0;

	map = new Pellet**[MAP_SIZE];
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
					numberOfPellets++;
					break;

				case PelletType(EXTRA):
					map[i][j] = new Pellet(PelletType(EXTRA),positionOnMap);
					numberOfPellets++;
					break;

				case PelletType(POWER):
					map[i][j] = new Pellet(PelletType(POWER),positionOnMap);
					numberOfPellets++;
					break;
				}
			}
		}
	}
	file.close();
}

Pellet*** Pellet::getMap()
{
	return map;
}

int Pellet::collectPelletFromMap(int* positionOnMap)
{
	if (map[positionOnMap[0]][positionOnMap[1]] != NULL)
	{
		int value = map[positionOnMap[0]][positionOnMap[1]]->getValue();
		map[positionOnMap[0]][positionOnMap[1]] = NULL;
		numberOfPellets--;
		return value;
	}

	return 0;
}

bool Pellet::isAllCollected()
{
	return (numberOfPellets == 0);
}