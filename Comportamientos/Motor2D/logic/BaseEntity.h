#ifndef __BASE_ENTITY__
#define __BASE_ENTITY__

#include <stdio.h>
#include "../include/sprite.h"
#include "../include/image.h"

class BaseScene;


class BaseEntity
{
public:
	BaseEntity( BaseScene* scene, Image* image, Scene::Layer layer = Scene::LAYER_BACK );
	~BaseEntity();
	virtual void Update( double elapsedTime ) = 0;
	Sprite* GetSprite() const;

private:
	Sprite* m_sprite;
	BaseScene* m_baseScene;
	int m_id;
};

#endif