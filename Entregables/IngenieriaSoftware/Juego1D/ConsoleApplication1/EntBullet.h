#ifndef __ENTITY_BULLET__
#define __ENTITY_BULLET__

#include "stdafx.h"


class EntBullet : public Entity
{
public:
	EntBullet();
	~EntBullet();

	bool Init( const EntHero* hero, MovementDirection direction, bool inGame );	
	void End();

	virtual void Update();
	virtual void Render();

private:
	MovementDirection m_direction;
};

#endif