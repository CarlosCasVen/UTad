#ifndef  __PLAYER_ENTITY__
#define __PLAYER_ENTITY__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"

enum eInputCode;


class PlayerEntity : public BaseEntity
{
public:
    PlayerEntity (  const rapidjson::Value* params );
    ~PlayerEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

private:
    void CreateBullet( double x, double y, double xDir, double yDir );

    eInputCode m_up, m_down, m_right, m_left, m_shoot;
    double     m_bulletSpeed;
};


#endif