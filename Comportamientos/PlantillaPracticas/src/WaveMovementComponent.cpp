#include "../logic/logic.h"
#include "../include/u-gine.h"
#include <ctime>


WaveMovementComponent::WaveMovementComponent()
{
    m_incrementX = m_incrementY = 0;
    SetType( EWaveMovement );
}
	
WaveMovementComponent::~WaveMovementComponent()   
{
}

TError WaveMovementComponent::Init()
{
    return OK;
}

void WaveMovementComponent::End()
{
    
}

void WaveMovementComponent::Update( double elapsedTime )
{
    m_x += DegCos( m_incrementX ) * m_distanceX * elapsedTime;
    m_y += DegSin( m_incrementY ) * m_distanceY * elapsedTime;
    m_incrementX += m_speedX * elapsedTime;
    m_incrementY += m_speedY * elapsedTime;
}

void WaveMovementComponent::SetSpeed( double speedX,  double speedY )
{
    m_speedX = speedX;
    m_speedY = speedY;
}
    
void WaveMovementComponent::SetInitialPos( double x, double y )
{
    m_x = x;
    m_y = y;
}
    
void WaveMovementComponent::SetDistance( double distanceX, double distanceY )
{
    m_distanceX = distanceX;
    m_distanceY = distanceY;
}

double WaveMovementComponent::GetSpeedX() const
{
    return m_speedX;
}

double WaveMovementComponent::GetSpeedY() const
{
    return m_speedY;
}

double WaveMovementComponent::GetX() const
{
    return m_x;
}

double WaveMovementComponent::GetY() const
{
    return m_y;
}

double WaveMovementComponent::GetDistanceX() const
{
    return m_distanceX;
}

double WaveMovementComponent::GetDistanceY() const
{
    return m_distanceY;
}