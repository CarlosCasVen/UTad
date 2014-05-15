#ifndef __ISCENE__
#define __ISCENE__

#include "../include/scene.h"

class Sprite;
class IEntity;
class LabelComponent;

class IScene
{
public:
    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual void Update( double elapsedTime ) = 0;
    virtual void Render() = 0;

    virtual void AddEntity   ( IEntity* entity )                     = 0;
    virtual void RemoveEntity( IEntity* entity )                     = 0;
    virtual void AddSprite   ( Sprite* sprite, Scene::Layer layer  ) = 0;
    virtual void RemoveSprite( Sprite* sprite )						 = 0;
    virtual void AddFont   ( LabelComponent* labelComponent )        = 0;
	virtual void RemoveFont( LabelComponent* labelComponent )        = 0;

};


#endif