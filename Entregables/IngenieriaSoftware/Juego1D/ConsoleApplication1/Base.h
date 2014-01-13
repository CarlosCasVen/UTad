#ifndef __BASE__
#define __BASE__


const char KEY_TO_MPVE_RIGHT = 'd';
const char KEY_TO_MOVE_LEFT = 'a';
const char KEY_TO_SHOOT_RIGHT = 'm';
const char KEY_TO_SHOOT_LEFT = 'n';
const char KEY_TO_EXIT = 27;

const char SYMBOL_HERO = 'X';
const char SYMBOL_ENEMY = 'O';
const char SYMBOL_BULLET_RIGHT = '>';
const char SYMBOL_BULLET_LEFT = '<';
const char SYMBOL_RAIN = '|';

const unsigned int NUMBER_OF_SPACES = 10;
const unsigned int GROUND_HEIGHT = 15;
const unsigned int WORLD_WIDTH = 60;
const unsigned int RAIN_DROP_MAX_TIME_LIFE = 60;
const unsigned int MAX_NUM_ENEMIES = 2;
const unsigned int MAX_NUM_BULLETS = 4;
const unsigned int MAX_NUM_RAIN_DROPS = 5;
const unsigned int MAX_TIME_BETWEEN_ENEMIES = 50;
const unsigned int MAX_TIME_BETWEEN_RAIN_DROPS = 10;

const bool IN_GAME = true;

enum NextAction
{
	HeroNoMovement,
	HeroMoveRight,
	HeroMoveLeft,
	HeroShootRight,
	HeroShootLeft,
	EndGame
};

enum EntityType
{
	Hero,
	Enemy,
	DropRain,
	Bullet
};

enum MovementDirection
{
	NoDirection,
	RightDirection,
	LeftDirection
};

#endif