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
	m_xMin = IScreenManager::Instance().TransformToScreenPointX( x );
    m_yMin = IScreenManager::Instance().TransformToScreenPointY( y );
}

//-------------------------------------
//
//-------------------------------------
void BoundComponent::SetMaxBound( double x, double y )
{
	m_xMax = IScreenManager::Instance().TransformToScreenPointX( x );
	m_yMax = IScreenManager::Instance().TransformToScreenPointY( y );
}

//-------------------------------------
//
//-------------------------------------
bool BoundComponent::IsInBounds()
{
	double xPos = Screen::Instance().GetMouseX();
	double yPos = Screen::Instance().GetMouseY();

    if( m_xMin <=  xPos && m_xMax >=  xPos  && 
        m_yMin <=  yPos && m_yMax >=  yPos  )        
        return true; 
    return false;
}