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
    TError error = OK;
    
    #define TYPE ELiveComponent \
    SetType( TYPE );
    #undef TYPE

    return error;
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
void LiveComponent::ReceiveEvent ( Event& newEvent )
{
   /* switch( newEvent.GetType() )
    {
    default: break;
    }*/
}

//-------------------------------------
//
//-------------------------------------
unsigned long int LiveComponent::GetListenerId() const
{
    return GetId();
}

//-------------------------------------
//
//-------------------------------------
void LiveComponent::SubstractLive( unsigned int damage )
{
    if( m_live < damage ) m_live = 0;
    else                  m_live -= damage;
}