#include "Camera.h"

void Camera::setCamera(float* pacManPosition)
{
	gluLookAt(
		pacManPosition[Dimension(X)], CAMERA_Y+zoom, pacManPosition[Dimension(Z)] + CAMERA_Z+zoom,
		pacManPosition[Dimension(X)], pacManPosition[Dimension(Y)], pacManPosition[Dimension(Z)],
		0.0f, 1.0f, 0.0f);
}

void Camera::zoomIn()
{
	if(zoom>maxZoom)
		zoom -= 0.2;
}

void Camera::zoomOut()
{
	if(zoom<minZoom)
		zoom += 0.2;
}