#ifndef __BASE_COMPONENT__
#define __BASE_COMPONENT__

#include "IComponent.h"

enum TError;
enum TComponent;
class IEntity;
class array;
class IComponent;


class BaseComponent 
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
	
	template <typename T>
	T* GetComponent( TComponent type );

private:
	unsigned int       m_id;
	IEntity*           m_entityParent;
    TComponent		   m_type;
	Array<IComponent*> m_components;

};



template <typename T>
T* BaseComponent::GetComponent( TComponent type )
{
	for( unsigned int i = 0; i < m_components.Size(); i++ )
	{
		if( type == m_components[i].GetType() ) return m_components[i];

	}
}

#endif