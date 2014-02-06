#ifndef __ENTITY_ENEMY__
#define __ENTITY_ENEMY__

#include "stdafx.h"


class EntEnemy : public Entity
{
public:
	EntEnemy();
	~EntEnemy();

	bool Init( const EntHero* hero, bool inGame );	
	void End();

	virtual void Update();
	virtual void Render();

private:
	MovementDirection m_direction;

};

#endif