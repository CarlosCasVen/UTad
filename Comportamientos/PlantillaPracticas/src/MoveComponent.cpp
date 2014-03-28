#include "../logic/logic.h"
#include "../include/u-gine.h"

//-------------------------------------
//
//-------------------------------------
MoveComponent::MoveComponent() : BaseComponent()
{
    m_xDirection = m_yDirection = m_speed = m_x = m_y = 0;
    SetType( EMove );
}

//-------------------------------------
//
//-------------------------------------
MoveComponent::~MoveComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError MoveComponent::Init()
{
   return OK;
}

//-------------------------------------
//
//-------------------------------------
void MoveComponent::End()
{
    m_xDirection = m_yDirection = m_speed = m_x = m_y = 0;
}

//-------------------------------------
//
//-------------------------------------
void MoveComponent::Update( double elapsedTime )
{
    
}

//-------------------------------------
//
//-------------------------------------
void MoveComponent::SetDirection( double x, double y )
{
    m_xDirection = x / abs( x );
    m_yDirection = y / abs( y );
}

//-------------------------------------
//
//-------------------------------------
void MoveComponent::SetSpeed( double speed  )
{
    m_speed = speed;
}

//-------------------------------------
//
//-------------------------------------
double MoveComponent::GetXIncrement() const
{
	return m_xDirection * m_speed * Screen::Instance().ElapsedTime();
}

//-------------------------------------
//
//-------------------------------------
double MoveComponent::GetYIncrement() const
{
    return m_yDirection * m_speed * Screen::Instance().ElapsedTime();
}

//-------------------------------------
//
//-------------------------------------    
double MoveComponent::GetSpeed()
{
    return m_speed;
}