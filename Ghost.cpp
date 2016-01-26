#include "Ghost.h"

#include<vector>
#include <cstdlib>
#include <ctime>

using namespace std;

Ghost::Ghost() : Figure()
{

}
Ghost::Ghost(int* positionOnMap) : Figure(positionOnMap)
{

}

void Ghost::randomMove()
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
			direction = possibleDirections[index];
			move(possibleDirections[index]);
		}
		else
		{
			move(Direction(FORWARD));
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
			
			int index = rand() % possibleDirections.size();
			direction = possibleDirections[index];
			move(possibleDirections[index]);
		}
		else
		{
			move(Direction(BACK));
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

			int index = rand() % possibleDirections.size();
			direction = possibleDirections[index];
			move(possibleDirections[index]);
		}
		else
		{
			move(Direction(RIGHT));
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

			int index = rand() % possibleDirections.size();
			direction = possibleDirections[index];
			move(possibleDirections[index]);
		}
		else
		{
			move(Direction(LEFT));
		}
		break;
	}
}
