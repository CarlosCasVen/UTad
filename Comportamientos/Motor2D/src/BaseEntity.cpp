#include "../logic/Logic.h"


//-------------------------------------
//
//-------------------------------------
BaseEntity::BaseEntity( const rapidjson::Value& params )
{
	m_params = &params;
}

//-------------------------------------
//
//-------------------------------------
TError BaseEntity::Init( IScene* m_scene )
{
    TError error = OK;
    m_id = IIdFactory::Instance().GetId();
    m_scene = m_scene;

    return error;
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::End()
{
    m_baseScene = NULL;
    m_sprite	= NULL;
}

//-------------------------------------
//
//-------------------------------------
Sprite* BaseEntity::GetSprite() const
{
    return m_sprite;
}

//-------------------------------------
//
//-------------------------------------
unsigned long int BaseEntity::GetId() const
{
    return m_id;
}

//-------------------------------------
//
//-------------------------------------
 void BaseEntity::SetScene( IScene& scene ) 
 {
	 m_baseScene = &scene;
 }

//-------------------------------------
//
//-------------------------------------
unsigned long int BaseEntity::GetListenerId() const
{
    return GetId();
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::SetSprite( Sprite* sprite )
{
    m_sprite = sprite;
}

//-------------------------------------
//
//-------------------------------------
Sprite* BaseEntity::GetSprite()
{
    return m_sprite;
}

//-------------------------------------
//
//-------------------------------------
const rapidjson::Value& BaseEntity::GetParams()
{
	return *m_params;
}