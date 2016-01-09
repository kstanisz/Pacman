#ifndef CAMERA_H
#define CAMERA_H

#include <windows.h>
#include <GL/gl.h>
#include "glut.h"
#include "Config.h"

class Camera
{
private:
	float zoom = 0;
	const float maxZoom = -1.5f;
	const float minZoom = 10.0f;
public:
	
	void setCamera(float* pacManPosition);
	void zoomIn();
	void zoomOut();
};

#endif