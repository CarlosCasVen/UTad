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

    virtual Sprite* CreateSprite ( Image& image, Scene::Layer layer = Scene::LAYER_BACK );

private:
	Array<IEntity*> m_entities;
	Scene*          m_scene;
    const String*   m_json;    

};


#endif