#include "../logic/Logic.h"
#include "../include/u-gine.h"

//-------------------------------------
//
//-------------------------------------
BoundComponent::BoundComponent () : BaseComponent()
{
    m_xMin = m_xMax = m_yMin = m_yMax = 0;
    SetType( EBound );
}

//-------------------------------------
//
//-------------------------------------
BoundComponent::~BoundComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError BoundComponent::Init()
{
    m_xMin = m_xMax = m_yMin = m_yMax = 0;

    return OK;
}

//-------------------------------------
//
//-------------------------------------
void BoundComponent::End ()
{
    m_xMin = m_xMax = m_yMin = m_yMax = 0;
}

//-------------------------------------
//
//-------------------------------------
void BoundComponent::Update( double elapsedTime )
{
}

//-------------------------------------
//
//-------------------------------------
void BoundComponent::SetMinBound( double x, double y )
{
    m_xMin = x;
    m_yMin = y;
}

//-------------------------------------
//
//-------------------------------------
void BoundComponent::SetMaxBound( double x, double y )
{
    m_xMax = x;
    m_yMax = y;
}

//-------------------------------------
//
//-------------------------------------
bool BoundComponent::IsInBounds()
{
    if( m_xMin <=  Screen::Instance().GetMouseX() && m_xMax >=  Screen::Instance().GetMouseX() && 
        m_yMin <=  Screen::Instance().GetMouseY() && m_xMax >=  Screen::Instance().GetMouseY() ) 
        
        return true; 
    return false;
}