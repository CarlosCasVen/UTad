#include "../logic/Logic.h"


BaseScene::BaseScene()
{
}


BaseScene::~BaseScene()
{
}



void BaseScene::AddEntity( const BaseEntity& entity, Scene::Layer layer )
{
	m_entitiesInScene.Add( (BaseEntity* ) &entity );

	if( image )
	{
		m_scene->CreateSprite( image, layer );
	}
}


void BaseScene::RemoveEntity( BaseEntity* entity )
{
}