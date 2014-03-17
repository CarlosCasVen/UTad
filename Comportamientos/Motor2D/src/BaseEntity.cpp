#include "../logic/logic.h"


//-------------------------------------
//
//-------------------------------------
BaseEntity::BaseEntity( const rapidjson::Value& params )
{
    m_params = &params;
    m_id     = IIdFactory::Instance().GetId(); //PREGUNTAR A TOMAS
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