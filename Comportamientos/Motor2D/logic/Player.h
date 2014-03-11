#ifndef __PLAYER__
#define __PLAYER__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"


class Sprite;
class BaseScene;
class IScene;


class Player : public BaseEntity
{
public:
    virtual TError Init( IScene* m_scene, const rapidjson::Value& params);
    virtual void   End ();

    virtual void Update( double ElpasedTime );

    virtual void ReceiveEvent( Event& newEvent );

private:
    void SubstractLive ( unsigned int damage );

    unsigned int m_live;

};


#endif