#ifndef __IGAME__
#define __IGAME__


class IGame
{
public:
    static IGame& Instance();

	virtual TError Init()   = 0;
	virtual void   End()    = 0;

	virtual void Update( double elapsedTime ) = 0;
	virtual void Render( double elapsedTime ) = 0;

};


#endif