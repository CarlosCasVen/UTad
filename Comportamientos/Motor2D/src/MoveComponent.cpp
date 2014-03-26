#include "../logic/logic.h"

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
    #define TYPE EMoveComponent \
    SetType( TYPE );
    #undef TYPE

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
    m_x = m_xDirection * m_speed * elapsedTime;
    m_y = m_xDirection * m_speed * elapsedTime;
}

//-------------------------------------
//
//-------------------------------------
void MoveComponent::SetDirection( double x, double y )
{
    m_xDirection = x / x;
    m_yDirection = y / y;
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
    return m_x;
}

//-------------------------------------
//
//-------------------------------------
double MoveComponent::GetYIncrement() const
{
    return m_y;
}

//-------------------------------------
//
//-------------------------------------    
double MoveComponent::GetSpeed()
{
    return m_speed;
}