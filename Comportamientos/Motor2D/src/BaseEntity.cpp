#include "../logic/logic.h"


//-------------------------------------
//
//-------------------------------------
BaseEntity::BaseEntity( const rapidjson::Value& params )
{
    m_params = &params;
    m_id     = IIdFactory::Instance().GetId(); //PREGUNTAR A TOMAS
}

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

void BaseEntity::AddComponent( IComponent* component )
{
	m_components.Add( component );
}