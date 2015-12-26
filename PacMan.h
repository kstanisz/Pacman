#ifndef PACMAN_H
#define PACMAN_H
#include "Figure.h"

class PacMan : public Figure
{
private:

public:

	PacMan(int* positionOnMap);

	void display();
};

#endif