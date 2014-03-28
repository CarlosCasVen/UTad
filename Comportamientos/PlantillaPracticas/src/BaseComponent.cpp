#include "../logic/logic.h"


//-------------------------------------
//
//-------------------------------------
BaseComponent::BaseComponent()
{
	m_id     = IIdFactory::Instance().GetId();
    m_type   = EBase;
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

//-------------------------------------
//
//-------------------------------------
IEntity* BaseComponent::GetParent()
{
    return m_entityParent;
}

//-------------------------------------
//
//-------------------------------------
IComponent::TComponent BaseComponent::GetType() const
{
    return m_type;
}

//-------------------------------------
//
//-------------------------------------
void BaseComponent::SetType( TComponent type )
{
    m_type = type;
}