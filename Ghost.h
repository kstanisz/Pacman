#ifndef GHOST_H
#define GHOST_H
#include "Figure.h"

class Ghost : public Figure
{
private:

public:

	Ghost();
	Ghost(int* positionOnMap);

	void randomMove();
};
#endif
