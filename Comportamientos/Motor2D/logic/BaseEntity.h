#ifndef __BASE_ENTITY__
#define __BASE_ENTITY__

#include <stdio.h>
#include "../include/sprite.h"
#include "../include/image.h"

class BaseScene;


class BaseEntity
{
public:
	BaseEntity( BaseScene* scene, Image* image );
	~BaseEntity();
	virtual void Update( double elapsedTime ) = 0;

private:
	Sprite* m_sprite;
	BaseScene* m_baseScene;
};

#endif