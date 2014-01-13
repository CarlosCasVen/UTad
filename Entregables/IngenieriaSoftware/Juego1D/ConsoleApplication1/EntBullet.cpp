#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
EntBullet::EntBullet() : Entity()
{
}
//---------------------------------------------

//---------------------------------------------
EntBullet::~EntBullet()
{
	End();
}
//---------------------------------------------

//---------------------------------------------
bool EntBullet::Init( const EntHero* hero, MovementDirection direction, bool inGame )
{
	bool returnedValue = false;
	m_direction = direction;

	switch( m_direction )
	{
	case RightDirection:
		returnedValue = Entity::Init( hero->GetPositionInWorld() + 1, true, inGame );
		break;
	case LeftDirection:
		returnedValue = Entity::Init( hero->GetPositionInWorld() - 1, true, inGame );
		break;
	default:
		returnedValue = Entity::Init( hero->GetPositionInWorld(), false, false );
		break;
	}

	return returnedValue;
}
//---------------------------------------------

//---------------------------------------------
void EntBullet::End()
{
	m_direction = NoDirection;
}
//---------------------------------------------

//---------------------------------------------
void EntBullet::Update()
{
	if( GetPositionInWorld() < 1 || GetPositionInWorld() > WORLD_WIDTH )
	{
		SetIsInGame( false );
	}
	else
	{
		switch( m_direction )
		{
		case RightDirection:
			MoveRight();
			break;
		case LeftDirection:
			MoveLeft();
			break;
		default:
			break;
		}
	}
}
//---------------------------------------------

//---------------------------------------------
void EntBullet::Render()
{
	if( IsInGame() )
	{
		DrawFunction::Gotoxy( NUMBER_OF_SPACES + GetPositionInWorld(), GROUND_HEIGHT );

		if( m_direction == RightDirection )
		{
			DrawFunction::PrintSimbolInWorld( SYMBOL_BULLET_RIGHT );
		}
		else if( LeftDirection )
		{
			DrawFunction::PrintSimbolInWorld( SYMBOL_BULLET_LEFT );
		}		
	}
}