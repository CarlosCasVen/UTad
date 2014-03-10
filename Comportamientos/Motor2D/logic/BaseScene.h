#ifndef __BASE_SCENE__
#define __BASE_SCENE__

#include "IScene.h"
#include "../include/array.h"
#include "../include/scene.h"


class IEntity;


class BaseScene : public IScene
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );
    virtual void Render( double elapsedTime );

    virtual void AddSprite      ( Sprite& sprite );
    virtual void RemoveSprite   ( Sprite& sprite );

private:
	Array<IEntity*> m_entities;
	Scene*          m_scene;
    Array<Sprite*>  m_sprite;

};


#endif