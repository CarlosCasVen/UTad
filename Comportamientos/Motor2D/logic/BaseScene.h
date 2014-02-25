#ifndef __BASE_SCENE__
#define __BASE_SCENE__

#include <stdio.h>
#include "../include/array.h"
#include "../include/scene.h"

class BaseEntity;


class BaseScene
{
public:
	BaseScene();
	~BaseScene();
	virtual void Update( double elapsedTime ) = 0;
	void AddEntity( const BaseEntity& entity, Scene::Layer layer = Scene::LAYER_BACK );
	void RemoveEntity( BaseEntity* entity );

private:
	Array<BaseEntity*> m_entitiesInScene;
	Scene* m_scene;
};

#endif