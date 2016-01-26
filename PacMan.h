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
	int openCloseJawCounter;
	bool openJaw;

	void increaseOpenCloseJawCounter();

public:

	PacMan();
	PacMan(int* positionOnMap);

	void setCommand(int command);
	void moveControl();
	bool isOpenJaw();
	int getScore();
	void collect();
	bool isCollision(Ghost** ghosts);
};

#endif