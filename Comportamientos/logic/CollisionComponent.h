#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"
#include "../include/sprite.h"
#include "ICollisionListener.h"



class CollisionComponent : public BaseComponent, ICollisionListener
{
public:
    CollisionComponent ();
	~CollisionComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    Sprite*                           GetCollisionSprite       ();
    Sprite::CollisionMode             GetCollisionMode         ();
    const Array<CollisionComponent*>& GetCollisionsCollisioning();

    void SetCollisionMode( Sprite::CollisionMode mode );
    void SetSprite       ( Sprite* sprite );

    virtual unsigned long int   GetCollisionId();
    virtual void                AddCollisioningComponent( ICollisionListener* collision );
    virtual CollisionComponent* GetCollisionComponent   ();
  
private:
    Sprite::CollisionMode            m_collisionMode;
    Array<CollisionComponent*>       m_componentsCollisioning;
    Sprite*                          m_sprite;
    
   
};

#endif