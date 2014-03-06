#include "../logic/Logic.h"



BaseEntity::BaseEntity( BaseScene* scene, Image* image, Scene::Layer layer )
{
	m_baseScene = scene;
	m_sprite = m_baseScene->CreateSprite( *image, layer );
}


BaseEntity::~BaseEntity()
{

}


Sprite* BaseEntity::GetSprite() const
{
	return m_sprite;
}