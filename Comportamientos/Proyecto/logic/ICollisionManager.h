#ifndef __ICOLLISION_MANAGER__
#define __ICOLLISION_MANAGER__


enum TError;
class CollisionComponent;

class ICollisionManager 
{
public:
    static ICollisionManager& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual void Update() = 0;

    virtual TError RegisterCollider  ( ICollisionListener* collision ) = 0;
    virtual void   UnregisterCollider( ICollisionListener* collision ) = 0;
};


#endif