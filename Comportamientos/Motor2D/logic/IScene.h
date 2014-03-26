#ifndef __ISCENE__
#define __ISCENE__

#include "../include/scene.h"

class Sprite;
class IEntity;

class IScene
{
public:
    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual void Update( double elapsedTime ) = 0;
    virtual void Render() = 0;

    virtual void AddEntity   ( IEntity* entity )                     = 0;
    virtual void AddSprite   ( Sprite* sprite, Scene::Layer layer  ) = 0;
    virtual void RemoveSprite( Sprite* sprite )						 = 0;

};


#endif