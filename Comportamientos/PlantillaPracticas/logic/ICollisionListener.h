#ifndef __ICOLLISION_LISTENER__
#define __ICOLLISION_LISTENER__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"
#include "../include/sprite.h"

class CollisionComponent;

class ICollisionListener
{
public:
    virtual unsigned long int   GetCollisionId()                                          = 0;
    virtual void                AddCollisioningComponent( ICollisionListener* collision ) = 0;
    virtual CollisionComponent* GetCollisionComponent   ()                                = 0;

};

#endif