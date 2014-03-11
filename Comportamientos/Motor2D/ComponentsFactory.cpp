#include "stdafx.h"
#include "ComponentsFactory.h"
#include "components/PlayerControllerComponent.h"

IComponentsFactory *g_CF = NULL;

// ***********************************************************************************
//
// ***********************************************************************************
IComponentsFactory *IComponentsFactory::get()
{
	if (!g_CF)
		g_CF = NEW(CComponentsFactory, ());
	return g_CF;
}

// ***********************************************************************************
//
// ***********************************************************************************
CComponentsFactory::CComponentsFactory()
{
	m_uComponentIdGen = 1;
	m_pInfo						= NULL;
}
CComponentsFactory::~CComponentsFactory()
{
	m_pInfo = NULL;
}

// ***********************************************************************************
//
// ***********************************************************************************
int  CComponentsFactory::init()
{
	return RET_OK;
}

// ***********************************************************************************
//
// ***********************************************************************************
void CComponentsFactory::end()
{
	SAFE_DELETE(g_CF);
}

// ***********************************************************************************
//
// ***********************************************************************************
int	CComponentsFactory::addClassesInfo(const rapidjson::Value *pInfo)
{
	if (pInfo)
		m_pInfo = &(*pInfo)["classes_components"];
	return m_pInfo ? RET_OK : RET_ERR;
}

// ***********************************************************************************
//
// ***********************************************************************************
IComponent *CComponentsFactory::getComponent(TType nType)
{
	return getComponent(nType, NULL);
}

// ***********************************************************************************
//
// ***********************************************************************************
IComponent *CComponentsFactory::getComponent(const rapidjson::Value *pInfo)
{
	return NULL;
}

// ***********************************************************************************
//
// ***********************************************************************************
IComponent *CComponentsFactory::getComponent(const char *pszClassName)
{
	return NULL;
}

// ***********************************************************************************
//
// ***********************************************************************************
void CComponentsFactory::releaseComponent(IComponent *pEntity)
{
}

// ***********************************************************************************
//
// ***********************************************************************************
IComponentsFactory::TType	CComponentsFactory::getComponentTypeByName	(const char *pszName)
{
	return IComponentsFactory::EInvalid;
}

// ***********************************************************************************
//
// ***********************************************************************************
IComponent *CComponentsFactory::getComponent (IComponentsFactory::TType nType, const rapidjson::Value *pInfo)
{
	IComponent *pRet = NULL;
	switch (nType)
	{
#define REG_COMPONENT(val, name) \
		case E##val: \
			pRet = NEW(C##val##Component, (generateComponentId(), pInfo)); \
			if (pRet) pRet->init(); \
		  break;
#include "REG_COMPONENTS.h"
#undef REG_COMONENT
		default:
			break;
	}
	return (pRet);
}

// ***********************************************************************************
//
// ***********************************************************************************
unsigned int CComponentsFactory::generateComponentId()
{
	return m_uComponentIdGen++;
}