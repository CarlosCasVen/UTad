#include "../logic/logic.h"

//-------------------------------------
//
//-------------------------------------
LiveComponent::LiveComponent () : BaseComponent()
{
    SetType( ELive );
}

//-------------------------------------
//
//-------------------------------------
LiveComponent::~LiveComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError LiveComponent::Init()
{
    return OK;
}

//-------------------------------------
//
//-------------------------------------
void LiveComponent::End ()
{
    m_live = 0xFFFFFFFF;
}

//-------------------------------------
//
//-------------------------------------
void LiveComponent::Update( double elapsedTime )
{
}

//-------------------------------------
//
//-------------------------------------
void LiveComponent::SetLive( unsigned int live )
{
    m_live = live;
}

//-------------------------------------
//
//-------------------------------------
unsigned int LiveComponent::GetLive() const
{
    return m_live;
}

//-------------------------------------
//
//-------------------------------------
void LiveComponent::SubstractLive( unsigned int damage )
{
    if( m_live < damage ) m_live = 0;
    else                  m_live -= damage;
}