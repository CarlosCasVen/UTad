#include "../stdafx.h"
#include "BaseComponent.h"

// ********************************************************************************
//
// ********************************************************************************
CBaseComponent::CBaseComponent(IComponentsFactory::TType nType, unsigned int uId, const rapidjson::Value *pInfo)
{
	m_pEntity			= NULL;;
	m_bActivated	= false;
	m_nType				= nType;
}

// ********************************************************************************
//
// ********************************************************************************
CBaseComponent::~CBaseComponent()
{
	m_pEntity			= NULL;
	m_bActivated	= false;
}

// ********************************************************************************
//
// ********************************************************************************
int	CBaseComponent::init()
{
	return RET_OK;
}

// ********************************************************************************
//
// ********************************************************************************
int	CBaseComponent::addedToEntity(IEntity *pEntity)
{
	m_pEntity = pEntity;
	return RET_ERR;
}

// ********************************************************************************
//
// ********************************************************************************
void CBaseComponent::removedFromEntity()
{
	m_pEntity = NULL;
}

// ********************************************************************************
//
// ********************************************************************************
void CBaseComponent::activate(bool bActivate)
{
	m_bActivated = bActivate;
}

// ********************************************************************************
//
// ********************************************************************************
void CBaseComponent::update(float fDelta)
{
}

// ********************************************************************************
//
// ********************************************************************************
bool CBaseComponent::manageEvent(TBaseEvent *pMessage)
{
	return false;
}

// ********************************************************************************
// GETTERS
// ********************************************************************************
IEntity *									CBaseComponent::getEntity		() { return m_pEntity;		}
bool											CBaseComponent::getActivated() { return m_bActivated;	}
IComponentsFactory::TType CBaseComponent::getType			() { return m_nType;			}
unsigned int							CBaseComponent::getId				() { return m_uId;			  }
const rapidjson::Value*		CBaseComponent::getInfo			() { return m_pInfo;			}

