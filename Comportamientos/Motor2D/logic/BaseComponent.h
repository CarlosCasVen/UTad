#ifndef __BASE_COMPONENT__
#define __BASE_COMPONENT__

#include "IComponent.h"

enum TError;


class BaseComponent : public IComponent
{
public:
	BaseComponent ();
	~BaseComponent();

	virtual TError Init() = 0;
	virtual void   End () = 0;

	virtual void Update( double elapsedTime ) = 0;

	virtual unsigned long int GetId	   ()            const;
	virtual void			  SetParent( IEntity* entity );
    virtual TComponent        GetType  ()		     const;

protected:
    IEntity* GetParent();
    void     SetType  ( TComponent type );

private:
	unsigned int   m_id;
	IEntity*       m_entityParent;
    TComponent     m_type;

};

#endif