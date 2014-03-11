#ifndef __ISCENE__
#define __ISCENE__


class IScene
{
public:
    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual void Update( double elapsedTime ) = 0;
    virtual void Render( double elapsedTime ) = 0;

    virtual Sprite* CreateSprite ( Image& image, Scene::Layer layer = Scene::LAYER_BACK ) = 0;
};


#endif