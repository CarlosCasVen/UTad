#include "../logic/Logic.h"
#include "../include/u-gine.h"

//-------------------------------------
//
//-------------------------------------
BoundEliminatorComponent::BoundEliminatorComponent () : BaseComponent()
{
    m_sprite = NULL;
    m_xMin = m_xMax = m_yMin = m_yMax = 0;
    SetType( EBound );
}

//-------------------------------------
//
//-------------------------------------
BoundEliminatorComponent::~BoundEliminatorComponent()
{
}

//-------------------------------------
//
//-------------------------------------
TError BoundEliminatorComponent::Init()
{

    return OK;
}

//-------------------------------------
//
//-------------------------------------
void BoundEliminatorComponent::End ()
{
    m_xMin = m_xMax = m_yMin = m_yMax = 0;
}

//-------------------------------------
//
//-------------------------------------
void BoundEliminatorComponent::Update( double elapsedTime )
{
    if( !IsInBounds() ) 
    {
        GetParent()->GetParentScene()->RemoveEntity( GetParent() );     
        GetParent()->GetParentScene()->RemoveSprite( m_sprite    );
    }
}

//-------------------------------------
//
//-------------------------------------
void BoundEliminatorComponent::SetMinBound( double x, double y )
{
	m_xMin = x;
    m_yMin = y;
}

//-------------------------------------
//
//-------------------------------------
void BoundEliminatorComponent::SetMaxBound( double x, double y )
{
	m_xMax = x;
	m_yMax = y;
}

//-------------------------------------
//
//-------------------------------------
bool BoundEliminatorComponent::IsInBounds()
{
    if( m_sprite )
    {
        double xPos = m_sprite->GetX();
	    double yPos = m_sprite->GetY();

        if( m_xMin <=  xPos && m_xMax >=  xPos  && 
              m_yMin <=  yPos && m_yMax >=  yPos  )        
        return true; 

        return false;
    }
    return true;
}

//-------------------------------------
//
//-------------------------------------
void BoundEliminatorComponent::SetSprite( Sprite* sprite )
{
    m_sprite = sprite;
}