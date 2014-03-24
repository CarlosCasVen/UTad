#ifndef __BASE_SCENE__
#define __BASE_SCENE__

#include "IScene.h"
#include "../include/array.h"
#include "../include/scene.h"


class BaseScene : public IScene, IListener
{
public:
    BaseScene( const String* sceneInfo );

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );
    virtual void Render();

    virtual void AddSprite   ( Sprite* sprite, Scene::Layer layer );
    virtual void RemoveSprite( Sprite* sprite );

    virtual void              ReceiveEvent ( Event& newEvent );
    virtual unsigned long int GetListenerId()            const;

private:
    TError GenerateEntities();

    Array<IEntity*>   m_entities;
    Scene*            m_scene;
    const String*     m_sceneInfo;
    unsigned long int m_id;
};

#endif