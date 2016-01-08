#include "SolidCube.h"

GLfloat SolidCube::vertices[VERTICES] =
{ 
-0.5f, 0.0f, 0.5f,   0.5f, 0.0f, 0.5f,   0.5f, 1.0f, 0.5f,  -0.5f, 1.0f, 0.5f,
-0.5f, 1.0f, -0.5f,  0.5f, 1.0f, -0.5f,  0.5f, 0.0f, -0.5f, -0.5f, 0.0f, -0.5f,
0.5f, 0.0f, 0.5f,   0.5f, 0.0f, -0.5f,  0.5f, 1.0f, -0.5f,  0.5f, 1.0f, 0.5f,
-0.5f, 0.0f, -0.5f,  -0.5f, 0.0f, 0.5f,  -0.5f, 1.0f, 0.5f, -0.5f, 1.0f, -0.5f
};

GLfloat SolidCube::texCoords[TEX_COORDS]=
{ 
0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0
};

GLubyte SolidCube::cubeIndices[CUBE_INDICES]=
{ 
0,1,2,3, 
4,5,6,7, 
3,2,5,4, 
7,6,1,0,
8,9,10,11, 
12,13,14,15 
};


void APIENTRY SolidCube::drawCube(GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glVertexPointer(3, GL_FLOAT, 0, vertices);

	glDrawElements(GL_QUADS, CUBE_INDICES, GL_UNSIGNED_BYTE, cubeIndices);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
}