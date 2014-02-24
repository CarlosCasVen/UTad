#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
EntHero::EntHero() : Entity()
{
}
//---------------------------------------------

//---------------------------------------------
EntHero::~EntHero()
{
	End();
}
//---------------------------------------------

//---------------------------------------------
bool EntHero::Init( unsigned int initialPosition, bool inGame )
{
	m_alive = true;
	return Entity::Init( initialPosition, true, inGame );
}
//---------------------------------------------

//---------------------------------------------
void EntHero::End()
{
	m_alive = false;
	m_direction = NoDirection;
}
//---------------------------------------------

//---------------------------------------------
void EntHero::Update()
{
	switch( m_direction )
	{
	case RightDirection:
		if( GetPositionInWorld() < WORLD_WIDTH )
		{
			MoveRight();
		}
		break;
	case LeftDirection:
		if( GetPositionInWorld() > 0 )
		{
			MoveLeft();
		}
		break;
	default:
		break;
	}
}
//---------------------------------------------

//---------------------------------------------
void EntHero::Render()
{
	if( IsInGame() && IsAlive() )
	{
		DrawFunction::Gotoxy( NUMBER_OF_SPACES + GetPositionInWorld(), GROUND_HEIGHT );
		DrawFunction::PrintSimbolInWorld( SYMBOL_HERO );
	}
}
//---------------------------------------------

//---------------------------------------------
void EntHero::SetIsAlive( bool alive )
{
	m_alive = alive;
}
//---------------------------------------------

//---------------------------------------------
void EntHero::SetMovementDirection( MovementDirection direction )
{
	m_direction = direction;
}
//---------------------------------------------

//---------------------------------------------
bool EntHero::IsAlive() const
{
	return m_alive;
}