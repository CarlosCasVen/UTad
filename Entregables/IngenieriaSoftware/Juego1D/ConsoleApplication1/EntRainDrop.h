#ifndef __ENTITY_RAIN_DROP__
#define __ENTITY_RAIN_DROP__

#include "stdafx.h"

class EntRainDrop : public Entity
{
public:
	EntRainDrop();
	~EntRainDrop();

	bool Init( bool inGame );	
	void End();

	virtual void Update();
	virtual void Render();

private:
	unsigned int m_timeOfLive;
};

#endif