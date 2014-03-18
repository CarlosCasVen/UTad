#include "../logic/logic.h"


BaseComponent::BaseComponent()
{
	m_id = IIdFactory::Instance().GetId();
}

//-------------------------------------
//
//-------------------------------------
BaseComponent::~BaseComponent()
{
	m_entityParent = NULL;
}

//-------------------------------------
//
//-------------------------------------
unsigned long int BaseComponent::GetId() const
{
	return m_id;
}

//-------------------------------------
//
//-------------------------------------
void BaseComponent::SetParent( IEntity* entity )
{
	m_entityParent = entity;
}