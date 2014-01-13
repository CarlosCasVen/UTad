#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
EntRainDrop::EntRainDrop()
{
}
//---------------------------------------------

//---------------------------------------------
EntRainDrop::~EntRainDrop()
{
	End();
}
//---------------------------------------------

//---------------------------------------------
bool EntRainDrop::Init( bool inGame )
{
	unsigned int initialPosition = rand() % WORLD_WIDTH;
	m_timeOfLive = rand() % RAIN_DROP_MAX_TIME_LIFE;

	return Entity::Init( initialPosition, true, inGame );
}
//---------------------------------------------

//---------------------------------------------
void EntRainDrop::End()
{
	m_timeOfLive = 0;
}
//---------------------------------------------

//---------------------------------------------
void EntRainDrop::Update()
{
	if( m_timeOfLive > 0 )
	{
		m_timeOfLive--;
	}
	else
	{
		SetIsInGame( false );
	}
}
//---------------------------------------------

//---------------------------------------------
void EntRainDrop::Render()
{
	if( IsInGame() )
	{
		DrawFunction::Gotoxy( NUMBER_OF_SPACES + GetPositionInWorld(), GROUND_HEIGHT - m_timeOfLive );
		DrawFunction::PrintSimbolInWorld( SYMBOL_RAIN );
	}
}