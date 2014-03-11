#include "stdafx.h"
#include "EntitiesFactory.h"
#include "entities/ButtonEntity.h"
#include "entities/ComponentsEntity.h"
#include "entities/HardcodedPlayerEntity.h"

CEntitiesFactory *g_EF = NULL;

CEntitiesFactory::TEntityInfo CEntitiesFactory::s_aEntitiesInfo[] = 
{
#define REG_ENTITY(Val, name) \
	{E##Val, name},
#include "REG_ENTITIES.h"
#undef REG_ENTITY
};

// ****************************************************************************************
//
// ****************************************************************************************
IEntitiesFactory *IEntitiesFactory::get()
{
	if (!g_EF)
	{
		g_EF = NEW(CEntitiesFactory, ());
		ASSERT(g_EF);
	}
	return g_EF;
}

CEntitiesFactory::CEntitiesFactory()
{
	m_pEntitiesClassesInfo	= NULL;
	m_uEntityIdGen					= 1;
}

CEntitiesFactory::~CEntitiesFactory()
{
}

// ****************************************************************************************
//
// ****************************************************************************************
int  CEntitiesFactory::init()
{
	return RET_OK;
}

// ****************************************************************************************
//
// ****************************************************************************************
void CEntitiesFactory::end ()
{
	SAFE_DELETE(g_EF);
}

// ****************************************************************************************
//
// ****************************************************************************************
int	CEntitiesFactory::addClassesInfo(const rapidjson::Value *pInfo)
{
	if (pInfo)
		m_pEntitiesClassesInfo =  &(*pInfo)["classes"];
	return m_pEntitiesClassesInfo ? RET_OK : RET_ERR;
}

// ****************************************************************************************
//
// ****************************************************************************************
IEntity *CEntitiesFactory::getEntity(IEntitiesFactory::TType nType)
{
	return getEntity(nType, NULL);
}

// ****************************************************************************************
//
// ****************************************************************************************
IEntity *CEntitiesFactory::getEntity(const rapidjson::Value *pInfo)
{
	IEntity *pRet = NULL;

	if (pInfo)
	{
		IEntitiesFactory::TType nType = getEntityTypeByName((*pInfo)["type"].GetString());
		pRet = getEntity(nType, pInfo);
	}

	return pRet;
}

// ****************************************************************************************
//
// ****************************************************************************************
IEntity *CEntitiesFactory::getEntity(IEntitiesFactory::TType nType, const rapidjson::Value *pInfo)
{
	IEntity *pRet = NULL;
	switch (nType)
	{
#define REG_ENTITY(val, name) \
		case E##val: \
			pRet = NEW(C##val##Entity, (generateEntityId(), pInfo)); \
			if (pRet) pRet->init(); \
		  break;
#include "REG_ENTITIES.h"
#undef REG_ENTITY
		default:
			break;
	}
	return (pRet);
}

// ****************************************************************************************
//
// ****************************************************************************************
IEntity *CEntitiesFactory::getEntity(const char *pszClassName)
{
	return NULL;
}

// ****************************************************************************************
//
// ****************************************************************************************
void CEntitiesFactory::releaseEntity(IEntity *pEntity)
{
	DEL(reinterpret_cast<CBaseEntity *>(pEntity));
}

// ****************************************************************************************
//
// ****************************************************************************************
CEntitiesFactory::TType CEntitiesFactory::getEntityTypeByName(const char *pszName)
{
	CEntitiesFactory::TType nRet = EInvalid;
	if (pszName)
	{
		int i = 0;
		while ((nRet == EInvalid) && (i < NUM_ENTITY_TYPES))
		{
			if (!strcmp(pszName, s_aEntitiesInfo[i].pszTypeName))
				nRet = s_aEntitiesInfo[i].nType;
			else
				i++;
		}
	}
	return nRet;
}

// ****************************************************************************************
//
// ****************************************************************************************
unsigned int CEntitiesFactory::generateEntityId()
{
	return m_uEntityIdGen++;
}