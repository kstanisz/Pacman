#ifndef PACMAN_H
#define PACMAN_H
#include "Figure.h"

class PacMan : public Figure
{
private:

	int command;

public:

	PacMan(int* positionOnMap);

	void setCommand(int command);
	void moveControl();
	void display();
};

#endif