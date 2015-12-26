#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"

using namespace std;

class Figure
{
protected:

	float* positionOnScene;
	int* positionOnMap;
	static int** map;
	int stateHorizontal;
	int stateVertical;

public:

	Figure(int* positionOnMap)
	{
		this->positionOnMap = positionOnMap;
		stateHorizontal = 0;
		stateVertical = 0;

		positionOnScene = new float[DIMENSIONS];
		positionOnScene[Dimension(X)] = float(positionOnMap[1]) * WALL_BRICK_SIZE + TRANSLATION_X;
		positionOnScene[Dimension(Y)] = float(0.25 / 2.0);
		positionOnScene[Dimension(Z)] = float(positionOnMap[0]) * WALL_BRICK_SIZE + TRANSLATION_Z;
	}

	void setPosition(float* positionOnScene)
	{
		this->positionOnScene = positionOnScene;
	}

	float* getPosition()
	{
		return positionOnScene;
	}

	void moveForward()
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
	}

	void moveBack()
	{
		if (stateHorizontal != 0)
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
	}

	void moveRight()
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
	}

	void moveLeft()
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
	}

	static int** createMap()
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

	virtual void display() = 0;
};


