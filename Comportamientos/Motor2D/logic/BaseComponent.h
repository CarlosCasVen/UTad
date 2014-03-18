#ifndef __BASE_COMPONENT__
#define __BASE_COMPONENT__

#include "IComponent.h"

class BaseComponent : public IComponent
{
public:
	BaseComponent ();
	~BaseComponent();

	virtual TError Init() = 0;
	virtual void   End () = 0;

	virtual void Update( double elapsedTime ) = 0;

	virtual unsigned long int GetId	   () const;
	virtual void			  SetParent( IEntity* entity );

private:
	unsigned int   m_id;
	const IEntity* m_entityParent;


};

#endif