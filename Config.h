#ifndef CONFIG_H
#define CONFIG_H

#define WINDOW_SIZE 500
#define WINDOW_POSITION 0
#define DISPLAY_TIME 50
#define RESPAWN_TIME 100

#define GHOSTS 4
#define LIFES 3
#define NORMAL_PELLET_VALUE 10
#define EXTRA_PELLET_VALUE 15
#define POWER_PELLET_VALUE 30


#define CAMERA_Y 3.0f
#define CAMERA_Z 2.0f

#define DIMENSIONS 3
#define MAP_SIZE 28
#define STEP 0.125f

#define WALL_BRICK_SIZE 0.5f
#define TRANSLATION_X -7.25f
#define TRANSLATION_Z -13.75f

enum Dimension
{
	X=0,
	Y=1,
	Z=2
};

enum Direction
{
	FORWARD,
	BACK,
	RIGHT,
	LEFT
};

enum PelletType
{
	NO_PELLET=0,
	NORMAL=1,
	EXTRA=2,
	POWER=3,
};

#endif
