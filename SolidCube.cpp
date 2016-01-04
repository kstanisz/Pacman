#include "SolidCube.h"

using namespace std;

void APIENTRY SolidCube::drawCube(GLdouble size, GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(-size/2, -size/2, size/2);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(size/2, 0.0f); glVertex3f(size/2, -size/2, size/2);	// Bottom Right Of The Texture and Quad
		glTexCoord2f(size/2, size/2); glVertex3f(size/2, size/2, size/2);		// Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, size/2); glVertex3f(-size/2, size/2, size/2);	// Top Left Of The Texture and Quad
																	// Back Face
		glTexCoord2f(size/2, 0.0f); glVertex3f(-size/2, -size/2, -size/2);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(size/2, size/2); glVertex3f(-size/2, size/2, -size/2);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, size/2); glVertex3f(size/2, size/2, -size/2);	// Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(size/2, -size/2, -size/2);  // Bottom Left Of The Texture and Quad
																   // Top Face
		glTexCoord2f(0.0f, size/2); glVertex3f(-size/2, size/2, -size/2);  // Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-size/2, size/2, size/2);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(size/2, 0.0f); glVertex3f(size/2, size/2, size/2);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(size/2, size/2); glVertex3f(size/2, size/2, -size/2);  // Top Right Of The Texture and Quad
																  // Bottom Face
		glTexCoord2f(size/2, size/2); glVertex3f(-size/2, -size/2, -size/2);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, size/2); glVertex3f(size/2, -size/2, -size/2);  // Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(size/2, -size/2, size/2);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(size/2, 0.0f); glVertex3f(-size/2, -size/2, size/2);  // Bottom Right Of The Texture and Quad
																   // Right face
		glTexCoord2f(size/2, 0.0f); glVertex3f(size/2, -size/2, -size/2);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(size/2, size/2); glVertex3f(size/2, size/2, -size/2);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, size/2); glVertex3f(size/2, size/2, size/2);  // Top Left Of The Texture and Quad
		glTexCoord2f(0.0f, 0.0f); glVertex3f(size/2, -size/2, size/2);  // Bottom Left Of The Texture and Quad
																  // Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-size/2, -size/2, -size/2);  // Bottom Left Of The Texture and Quad
		glTexCoord2f(size/2, 0.0f); glVertex3f(-size/2, -size/2, size/2);  // Bottom Right Of The Texture and Quad
		glTexCoord2f(size/2, size/2); glVertex3f(-size/2, size/2, size/2);  // Top Right Of The Texture and Quad
		glTexCoord2f(0.0f, size/2); glVertex3f(-size/2, size/2, -size/2);  // Top Left Of The Texture and Quad

	glEnd();

	glDisable(GL_TEXTURE_2D);
}

