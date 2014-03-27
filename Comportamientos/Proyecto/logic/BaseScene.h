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

    virtual void AddEntity   ( IEntity* entity );
	virtual void RemoveEntity( IEntity* entity );

private:
    TError GenerateEntities();
	void   DestroyEntities ();
    void   AddEntities     ();

    Array<IEntity*>   m_entities;
	Array<IEntity*>   m_entitiesToDelete;
    Array<IEntity*>   m_entitiesToAdd;
    Scene*            m_scene;
    const String*     m_sceneInfo;
    unsigned long int m_id;
};

#endif