#ifndef GHOST_H
#define GHOST_H
#include "Figure.h"

class Ghost : public Figure
{
private:

public:

	Ghost(int* positionOnMap);

	void display();
	void move();
};
#endif
