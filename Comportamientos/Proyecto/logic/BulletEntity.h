#ifndef __BULLET_ENTITY__
#define __BULLET_ENTITY__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"


class Sprite;
class IScene;


class BulletEntity : public BaseEntity
{
public:
    BulletEntity (  const rapidjson::Value* params );
    ~BulletEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

    void SetDirection( double x, double y );
    void SetSpeed    ( double speed );
    void SetPosition ( double x, double y, double z = 0 );

};


#endif