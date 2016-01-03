#ifndef PACMAN_H
#define PACMAN_H
#include "Ghost.h"
#include "Figure.h"
#include "Pellet.h"

class PacMan : public Figure
{
private:

	int command;
	int score;

public:

	PacMan();
	PacMan(int* positionOnMap);

	void setCommand(int command);
	void moveControl();
	int getScore();
	void collect();
	bool isCollision(Ghost** ghosts);
	void display();
};

#endif