#ifndef __ENTITY_HERO__
#define __ENTITY_HERO__

#include "stdafx.h"


class EntHero : public Entity
{
public:
	EntHero();
	~EntHero();

	bool Init( unsigned int initialPosition, bool inGame );
	void End();

	virtual void Update();
	virtual void Render();

	void SetIsAlive( bool alive );
	void SetMovementDirection( MovementDirection direction );

	bool IsAlive() const;

private:
	bool m_alive;

	MovementDirection m_direction;
};

#endif