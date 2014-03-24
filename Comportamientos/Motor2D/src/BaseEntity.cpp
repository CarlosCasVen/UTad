#include "../logic/logic.h"


//-------------------------------------
//
//-------------------------------------
BaseEntity::BaseEntity( const rapidjson::Value& params )
{
    m_params = &params;
    m_id     = IIdFactory::Instance().GetId();
}

//-------------------------------------
//
//-------------------------------------

TError BaseEntity::Init()
{
    TError error = OK;

    if( !m_params->HasMember( "Components" ) ) return ERROR;

    IComponent* newComponent;

    for( unsigned int i = 0; i < (*m_params)["Components"].Size(); i++ )
    {
        newComponent = IComponentFactory::Instance().GetComponent( &(*m_params)["Components"][i], error );
        if( error == OK )
        {
            m_components.Add( newComponent );
            newComponent->Init();
        }
        else
        {
            IComponentFactory::Instance().RemoveComponent( newComponent );
        }
    }
     
    return error;
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::End()
{
    for( unsigned int i = 0; i < m_components.Size(); i++ ) IComponentFactory::Instance().RemoveComponent( m_components[i] );
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
void BaseEntity::SetParentScene( const IScene* parentScene )
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
const IScene* BaseEntity::GetParentScene()
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
}