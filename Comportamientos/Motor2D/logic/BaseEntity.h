#ifndef __BASE_ENTITY__
#define __BASE_ENTITY__

#include "IEntity.h"
#include "IComponent.h"
#include "../json/rapidjson/document.h"


class IScene;


class BaseEntity : public IEntity
{
public:
    BaseEntity( const rapidjson::Value* params );

    virtual TError Init() = 0;
    virtual void   End ();

    virtual void Update( double elapsedTime);

    virtual unsigned int GetId()						 const;
    virtual void         SetParentScene( IScene* parentScene );
    
    virtual IScene* GetParentScene () const;

protected:
    const rapidjson::Value& GetParams      () const;
	virtual void            AddComponent   ( IComponent* component );
	virtual void            RemoveComponent( IComponent* component );

    template <typename T>
    T* GetComponentByType( IComponent::TComponent type );

private:
    const rapidjson::Value* m_params;
    unsigned long int       m_id;
    IScene*                 m_scene; 
	Array<IComponent*>      m_components;

};


template <typename T>
T* BaseEntity::GetComponentByType( IComponent::TComponent type )
{
    bool found = false;
    unsigned int i = 0;

    for( i; i < m_components.Size() && !found; i++ )
    {
        m_components[i]->GetType();
        if( m_components[i]->GetType() == type ) found = true;
    }
    
    i--;

    if( found ) return reinterpret_cast<T*>( m_components[i] );
    else        return NULL;
}


#endif