#ifndef __BASE_COMPONENT__
#define __BASE_COMPONENT__

#include "IComponent.h"
#include "../json/rapidjson/document.h"

enum TError;
enum TComponent;
class IEntity;
class array;
class IComponent;


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

    IEntity* GetParent();

protected:
    void     SetType  ( TComponent type );

private:
	unsigned int            m_id;
	IEntity*                m_entityParent;
    TComponent		        m_type;

    friend class IComponent;
};


#endif