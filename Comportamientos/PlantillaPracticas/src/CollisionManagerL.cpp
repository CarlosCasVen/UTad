#include "../logic/Logic.h"
#include "../include/u-gine.h"

ICollisionManager* m_collisionManager = NULL;

//-------------------------------------
//
//-------------------------------------
ICollisionManager& ICollisionManager::Instance()
{
    if( !m_collisionManager ) m_collisionManager = NEW( CollisionManagerL, () );

    return *m_collisionManager;
}

//-------------------------------------
//
//-------------------------------------
TError CollisionManagerL::Init()
{
    return OK;
}

//-------------------------------------
//
//-------------------------------------
void CollisionManagerL::End()
{
    DEL( m_collisionManager );
}

//-------------------------------------
//
//-------------------------------------
void CollisionManagerL::CheckCollision( ICollisionListener* collision )
{
    Sprite* mainSprite = collision->GetCollisionComponent()->GetCollisionSprite();

    for( unsigned int i = 0; i < m_collisions.Size(); i++ )
        {
            Sprite* secundarySprite = m_collisions[i]->GetCollisionComponent()->GetCollisionSprite();

            if( mainSprite->CheckCollision( secundarySprite ) )   collision->AddCollisioningComponent( ( m_collisions[i] ) ); 
     }
}

//-------------------------------------
//
//-------------------------------------
TError CollisionManagerL::RegisterCollider( ICollisionListener* collision )
{
    bool found = false;

    for( unsigned int i = 0; i < m_collisions.Size() && !found; i++ )
    {
        if( m_collisions[i]->GetCollisionId() == collision->GetCollisionId() ) found = true;
    }

    if( found )  return LISTENER_REGISTRED;
    
    m_collisions.Add( collision );
    return OK;
}

//-------------------------------------
//
//-------------------------------------
void CollisionManagerL::UnregisterCollider( ICollisionListener* collision )
{
    bool found = false;
   
    for( unsigned int i = 0; i < m_collisions.Size() && !found; i++ )
    {
        if( m_collisions[i]->GetCollisionId() == collision->GetCollisionId() ) found = true;
    }
 
    if( found ) m_collisions.Remove(collision);

}

//-------------------------------------
//
//-------------------------------------
CollisionManagerL::CollisionManagerL()
{
}

//-------------------------------------
//
//-------------------------------------
CollisionManagerL::~CollisionManagerL()
{}