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
	BaseScene( String& filename );
	~BaseScene();
	virtual void Update( double elapsedTime );
	void AddEntity( const BaseEntity& entity  );
	Sprite* CreateSprite( Image& image, Scene::Layer layer = Scene::LAYER_BACK );
	void RemoveEntity( BaseEntity* entity );
	void RemoveSprite( Sprite& sprite );

private:
	Array<BaseEntity*> m_entitiesInScene;
	Scene* m_scene;
	const String& m_filename;
};

#endif