#ifndef  __PLAYER_ENTITY__
#define __PLAYER_ENTITY__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"

enum eInputCode;

class PlayerEntity : public BaseEntity
{
public:
    struct BulletParams
    {
        double       m_x;
        double       m_y;
        double       m_bulletSpeed;
	    int		     m_yDirection;
        unsigned int m_teamId;
    };

    PlayerEntity (  const rapidjson::Value* params );
    ~PlayerEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

private:
    void CreateBullet( BulletParams params );   

    eInputCode   m_up, m_down, m_right, m_left, m_shoot;
    BulletParams m_paramsBullet;   
    String       m_label;
};


#endif