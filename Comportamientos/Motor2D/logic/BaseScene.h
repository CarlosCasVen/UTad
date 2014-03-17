#ifndef __BASE_SCENE__
#define __BASE_SCENE__

#include "IScene.h"
#include "../include/array.h"
#include "../include/scene.h"


class BaseScene : public IScene
{
public:
    BaseScene( const String* sceneInfo );

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );
    virtual void Render( double elapsedTime );

    virtual void AddSprite   ( Sprite* sprite, Scene::Layer layer );
    virtual void RemoveSprite( Sprite* sprite );

private:
    TError GenerateEntities();

    Array<IEntity*> m_entities;
    Scene*          m_scene;
    const String*   m_sceneInfo;
};

#endif