#ifndef PELLET_H
#define PELLET_H

#include <windows.h>
#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"

class Pellet
{
private:

	PelletType type;
	int value;
	static Pellet*** map;
	
	int* positionOnMap;

public:

	Pellet();
	Pellet(PelletType type,int* positionOnMap);
	static int numberOfPellets;
	int getValue();
	void display();
	static Pellet*** createMap();
	static Pellet*** getMap();
	static int collectPelletFromMap(int* positionOnMap);
	static bool isAllCollected();
};

#endif