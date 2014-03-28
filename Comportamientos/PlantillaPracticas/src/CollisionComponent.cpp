#include "../logic/logic.h"
#include "../include/u-gine.h"

//-------------------------------------
//
//-------------------------------------
CollisionComponent::CollisionComponent() : BaseComponent()
{
    SetType( ECollision );
    m_collisionMode = Sprite::CollisionMode::COLLISION_NONE;
    m_sprite        = NULL;
}
	
//-------------------------------------
//
//-------------------------------------
CollisionComponent::~CollisionComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError CollisionComponent::Init()
{
    return OK;
}

//-------------------------------------
//
//-------------------------------------
void CollisionComponent::End()
{
}

//-------------------------------------
//
//-------------------------------------
void CollisionComponent::Update( double elapsedTime )
{
    m_componentsCollisioning.Clear();
}

//-------------------------------------
//
//-------------------------------------
Sprite* CollisionComponent::GetCollisionSprite()
{
    return m_sprite;
}
  
//-------------------------------------
//
//-------------------------------------
Sprite::CollisionMode CollisionComponent::GetCollisionMode()
{
    return m_collisionMode;
}
   
//-------------------------------------
//
//-------------------------------------
const Array<CollisionComponent*>& CollisionComponent::GetCollisionsCollisioning()
{
    return m_componentsCollisioning;
}

//-------------------------------------
//
//-------------------------------------
void CollisionComponent::SetCollisionMode( Sprite::CollisionMode mode )
{
    m_collisionMode = mode;
    m_sprite->SetCollision( m_collisionMode );
}

//-------------------------------------
//
//-------------------------------------
void CollisionComponent::SetSprite( Sprite* sprite )
{
    m_sprite = sprite;
}

//-------------------------------------
//
//-------------------------------------
unsigned long int CollisionComponent::GetCollisionId()
{
    return GetId();
}

//-------------------------------------
//
//-------------------------------------
void CollisionComponent::AddCollisioningComponent( ICollisionListener* collision )
{
    m_componentsCollisioning.Add( collision->GetCollisionComponent() );
}

//-------------------------------------
//
//-------------------------------------
CollisionComponent* CollisionComponent::GetCollisionComponent()
{
    return this;
}