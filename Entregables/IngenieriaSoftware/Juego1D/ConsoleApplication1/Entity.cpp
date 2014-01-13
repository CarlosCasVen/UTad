#include "stdafx.h"

//---------------------------------------------

//---------------------------------------------
Entity::Entity()
{
	m_isOk = false;
}
//---------------------------------------------

//---------------------------------------------
Entity::~Entity()
{
	End();
}


void Entity::End()
{
	m_isOk = false;
	m_inGame = false;
	m_positionInWorld = 0;
}
//---------------------------------------------

//---------------------------------------------
void Entity::SetIsInGame ( bool inGame )
{
	m_inGame = inGame;
}
//---------------------------------------------

//---------------------------------------------
void Entity::MoveRight()
{
	m_positionInWorld++;
}
//---------------------------------------------

//---------------------------------------------
void Entity::MoveLeft()
{
	m_positionInWorld--;
}
//---------------------------------------------

//---------------------------------------------
bool Entity::GetIsOk() const
{
	return m_isOk;
}
//---------------------------------------------

//---------------------------------------------
bool Entity::Init( unsigned int initialPosition, bool isOk, bool inGame )
{
	m_positionInWorld = initialPosition;
	m_isOk = isOk;
	m_inGame = inGame;

	return m_isOk;
}
//---------------------------------------------

//---------------------------------------------
bool Entity::IsInGame() const
{
	return m_inGame;
}
//---------------------------------------------

//---------------------------------------------
unsigned int Entity::GetPositionInWorld() const
{
	return m_positionInWorld;
}