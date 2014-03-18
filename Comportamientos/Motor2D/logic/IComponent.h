#ifndef __ICOMPONENT__
#define __ICOMPONENT__


enum TError;
class IEntity;


class IComponent
{
public:
	virtual TError Init() = 0;
	virtual void   End () = 0;

	virtual void Update( double elapsedTime ) = 0;

	virtual unsigned long int GetId	   ()		   const   = 0;
	virtual void			  SetParent( IEntity* entity ) = 0; 
};


#endif __ICOMPONENT__
