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
bool Entity::IsInGame() const
{
	return m_inGame;
}
//---------------------------------------------

//---------------------------------------------
bool Entity::GetIsOk() const
{
	return m_isOk;
}
//---------------------------------------------

//---------------------------------------------
unsigned int Entity::GetPositionInWorld() const
{
	return m_positionInWorld;
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
