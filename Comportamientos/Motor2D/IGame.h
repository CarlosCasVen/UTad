#ifndef ___IGAME____
#define ___IGAME____

class IGame
{
public:
	static IGame *get();

	virtual int   init() = 0;
	virtual void  end () = 0;

	virtual void update(float fDelta) = 0;
	virtual void render(float fDelta) = 0;

	virtual float getScaleX() = 0;
	virtual float getScaleY() = 0;
};
#endif