#ifndef __COLLISION_MANAGER__
#define __COLLISION_MANAGER__

#include "../include/array.h"
#include "ICollisionManager.h"

enum TError;
class CollisionComponent;

class CollisionManagerL : public ICollisionManager
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual void CheckCollision( ICollisionListener* collision );

    virtual TError RegisterCollider  ( ICollisionListener* collision );
    virtual void   UnregisterCollider( ICollisionListener* collision );

private:
    CollisionManagerL ();
    ~CollisionManagerL();

    Array<ICollisionListener*> m_collisions;

    friend class ICollisionManager;
};



#endif