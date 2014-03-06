#include "../logic/Logic.h"


BaseScene::BaseScene(  )
{
	m_scene = NEW( Scene, );
}


BaseScene::BaseScene( Image* background )
{
	m_scene = NEW( Scene, ( background )  );
}


BaseScene::~BaseScene()
{
	DEL( m_scene );
}


void BaseScene::AddEntity( const BaseEntity& entity )
{
	m_entitiesInScene.Add( (BaseEntity* ) &entity );
}


Sprite* BaseScene::CreateSprite( Image& image, Scene::Layer layer )
{
	return m_scene->CreateSprite( &image, layer );
}


void BaseScene::RemoveEntity( BaseEntity* entity )
{
	m_entitiesInScene.Remove( entity );
}


void BaseScene::RemoveSprite( Sprite& sprite )
{
	m_scene->DeleteSprite( &sprite );

}