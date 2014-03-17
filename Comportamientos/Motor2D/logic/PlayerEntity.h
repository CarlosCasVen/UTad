#ifndef __PLAYER__
#define __PLAYER__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"


class Sprite;
class IScene;


class PlayerEntity : public BaseEntity
{
public:
    PlayerEntity (  const rapidjson::Value& params );
    ~PlayerEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double ElpasedTime );

private:
    Sprite* m_sprite;

};


#endif