#include "../stdafx.h"
#include "ComponentsEntity.h"
#include "../IComponent.h"

// ****************************************************************************
//
// ****************************************************************************
CComponentsEntity::CComponentsEntity(unsigned int uId, const rapidjson::Value *pInfo) : 
	CBaseEntity(IEntitiesFactory::EComponents, uId, pInfo)
{
}

// ****************************************************************************
//
// ****************************************************************************
CComponentsEntity::CComponentsEntity(IEntitiesFactory::TType nType, unsigned int uId, const rapidjson::Value *pInfo) :
	CBaseEntity(nType, uId, pInfo)
{
}

// ****************************************************************************
//
// ****************************************************************************
CComponentsEntity::~CComponentsEntity()
{
}

// ****************************************************************************
//
// ****************************************************************************
int CComponentsEntity::addedToScene(CBaseScene *pScene)
{
	for (unsigned int i = 0; i < m_vComponents.size(); i++)
		m_vComponents[i]->activate(true);
	return RET_OK;
}

// ****************************************************************************
//
// ****************************************************************************
void CComponentsEntity::removedFromScene()
{
	for (unsigned int i = 0; i < m_vComponents.size(); i++)
		m_vComponents[i]->activate(false);
}

// ****************************************************************************
//
// ****************************************************************************
bool CComponentsEntity::manageEvent(TBaseEvent *pMessage)
{
	bool bRet = false;
	for (unsigned int i = 0; i < m_vComponents.size(); i++)
		bRet |= m_vComponents[i]->manageEvent(pMessage);
	return bRet;
}

// ****************************************************************************
//
// ****************************************************************************
void CComponentsEntity::update(float fDelta)
{
	for (unsigned int i = 0; i < m_vComponents.size(); i++)
		m_vComponents[i]->update(fDelta);
}

// ****************************************************************************
//
// ****************************************************************************
int CComponentsEntity::addComponent(IComponent *pComponent)
{
	m_vComponents.push_back(pComponent);
	return RET_OK;
}



