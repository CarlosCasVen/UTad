#ifndef ___GAME____
#define ___GAME____

#include "IGame.h"

class CGame : public IGame
{
public:
	virtual int   init();
	virtual void  end ();

	virtual void update(float fDelta);
	virtual void render(float fDelta);

	virtual float getScaleX();
	virtual float getScaleY();
};

#endif