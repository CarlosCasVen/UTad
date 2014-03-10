#ifndef __BASE_ENTITY__
#define __BASE_ENTITY__

#include "IEntity.h"


class Sprite;
class BaseScene;
class IScene;


class BaseEntity : public IEntity
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual void Update( double ElpasedTime ) = 0;

    virtual Sprite* GetSprite() const;

private:
	Sprite* m_sprite;
	IScene* m_baseScene;

};


#endif