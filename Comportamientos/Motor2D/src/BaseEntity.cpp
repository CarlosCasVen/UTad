#include "../logic/Logic.h"


//-------------------------------------
//
//-------------------------------------
TError BaseEntity::Init()
{
    TError error = OK;

    return error;
}

//-------------------------------------
//
//-------------------------------------
void BaseEntity::End()
{
    m_baseScene = NULL;
    m_sprite = NULL;
}

//-------------------------------------
//
//-------------------------------------
Sprite* BaseEntity::GetSprite() const
{
    return m_sprite;
}
