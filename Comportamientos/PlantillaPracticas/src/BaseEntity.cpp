#include "../logic/logic.h"


//-------------------------------------
//
//-------------------------------------
BaseEntity::BaseEntity( const rapidjson::Value* params )
{
    m_params = params;
    m_id     = IIdFactory::Instance().GetId();
}

//-------------------------------------
//
//-------------------------------------
TError BaseEntity::Init()
{
	for( unsigned int i = 0; i < m_components.Size(); i++ ) 
	{
		m_components[i]->SetParent( this );
		m_components[i]->Init();
	}

    return OK;
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::End()
{
    for( unsigned int i = 0; i < m_components.Size(); i++ )
	{
		m_components[i]->End();
		IComponentFactory::Instance().RemoveComponent( m_components[i] );
	}
	
	m_components.Clear();
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::Update( double elapsedTime)
{
	for( unsigned int i = 0; i < m_components.Size(); i++ ) m_components[i]->Update( elapsedTime );
}

//-------------------------------------
//
//-------------------------------------
unsigned int BaseEntity::GetId() const
{
    return m_id;
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::SetParentScene( IScene* parentScene )
{
    m_scene = parentScene;
}

//-------------------------------------
//
//-------------------------------------
const rapidjson::Value& BaseEntity::GetParams() const
{
    return *m_params;
}

//-------------------------------------
//
//-------------------------------------
IScene* BaseEntity::GetParentScene() const 
{
    return m_scene;
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::AddComponent( IComponent* component )
{
	m_components.Add( component );
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::RemoveComponent( IComponent* component )
{
    IComponentFactory::Instance().RemoveComponent( component );
    m_components.Remove( component );
}