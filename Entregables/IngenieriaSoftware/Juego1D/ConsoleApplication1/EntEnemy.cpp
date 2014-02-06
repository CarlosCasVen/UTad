#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
EntEnemy::EntEnemy() : Entity()
{
}
//---------------------------------------------

//---------------------------------------------
EntEnemy::~EntEnemy()
{
	End();
}
//---------------------------------------------

//---------------------------------------------
bool EntEnemy::Init( const EntHero* hero, bool inGame )
{
	if( hero )
	{
		unsigned int initialPosition = rand() % WORLD_WIDTH - 1;

		if( hero->GetPositionInWorld() > initialPosition )
		{
			m_direction = RightDirection;
		}
		else if( hero->GetPositionInWorld() < initialPosition )
		{
			m_direction = LeftDirection;
		}
		else
		{
			m_direction = NoDirection;
		}

		Entity::Init( initialPosition, true, inGame );
	}
	
	return GetIsOk();
}
//---------------------------------------------

//---------------------------------------------
void EntEnemy::End()
{
	m_direction = NoDirection;
}
//---------------------------------------------

//---------------------------------------------
void EntEnemy::Update()
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
void EntEnemy::Render()
{
	if( IsInGame() )
	{
		DrawFunction::Gotoxy( NUMBER_OF_SPACES + GetPositionInWorld(), GROUND_HEIGHT );
		DrawFunction::PrintSimbolInWorld( SYMBOL_ENEMY );
	}
}