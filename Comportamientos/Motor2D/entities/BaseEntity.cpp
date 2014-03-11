#include "../stdafx.h"
#include "BaseEntity.h"
#include "../include/sprite.h"
#include "../include/screen.h"
#include "../include/scene.h"
#include "../Game.h"
#include "../scenes/BaseScene.h"

// ********************************************************************************
//
// ********************************************************************************
CBaseEntity::CBaseEntity(IEntitiesFactory::TType nType, unsigned int uId, const rapidjson::Value *pInfo)
{
	m_pInfo				= pInfo;
	m_pScene			= NULL;
	m_pSpriteInfo	= NULL;
	m_nType				= nType;
	m_uId					= uId;
	m_pszName			= NULL;
	m_iPosX       = 0;
	m_iPosY       = 0;
}

// ********************************************************************************
//
// ********************************************************************************
CBaseEntity::~CBaseEntity()
{
	freeResources();
}

// ********************************************************************************
//
// ********************************************************************************
int CBaseEntity::init()
{
	int iRet = RET_ERR;
	if (m_pInfo)
	{
		m_pSpriteInfo = ISpritesFactory::get()->getSprite((*m_pInfo)["sprite"].GetString());
		ASSERT(m_pSpriteInfo);
		if (m_pSpriteInfo)
		{
			m_iPosX		= static_cast<int>(((*m_pInfo)["x"].GetDouble() * Screen::Instance().GetWidth())  / 100.0);
			m_iPosY		= static_cast<int>(((*m_pInfo)["y"].GetDouble() * Screen::Instance().GetHeight()) / 100.0);
			m_iPosZ		= static_cast<int>(((*m_pInfo)["z"].GetDouble()));
			double scaleX		= (*m_pInfo)["scale_x"].GetDouble() * IGame::get()->getScaleX();
			double scaleY		= (*m_pInfo)["scale_y"].GetDouble() * IGame::get()->getScaleY();
			double rotation = (*m_pInfo)["rotation"].GetDouble() * IGame::get()->getScaleY();
			m_pSpriteInfo->m_pSprite->SetPosition(m_iPosX, m_iPosY, m_iPosZ);
			m_pSpriteInfo->m_pSprite->SetScale(scaleX, scaleY);
			m_pSpriteInfo->m_pSprite->SetAngle(rotation);
			iRet = RET_OK;
		}
	}
	return iRet;
}

// ********************************************************************************
// GETTERS
// ********************************************************************************
IEntitiesFactory::TType			  CBaseEntity::getType() { return m_nType;	}
unsigned int								  CBaseEntity::getId	() { return m_uId;		}
const char *									CBaseEntity::getName() { return m_pszName;}
int														CBaseEntity::getPosX() { return m_iPosX;	}
int														CBaseEntity::getPosY() { return m_iPosY;	}
int														CBaseEntity::getPosZ() { return m_iPosZ;	}

// ********************************************************************************
//
// ********************************************************************************
void CBaseEntity::setPos(int x, int y, int z)
{
	m_iPosX = x;
	m_iPosY = y;
	m_iPosZ = z;
}

// ********************************************************************************
//
// ********************************************************************************
int CBaseEntity::addedToScene(CBaseScene *pScene)
{
	int iRet = RET_ERR;
	m_pScene = pScene;
	if (m_pScene && m_pSpriteInfo)
		iRet = m_pScene->addSprite(m_pSpriteInfo);
	return iRet;
}

// ********************************************************************************
//
// ********************************************************************************
void CBaseEntity::removedFromScene()
{
	if (m_pScene && m_pSpriteInfo)
	{
		m_pScene->removeSprite(m_pSpriteInfo);
		m_pScene = NULL;
	}
}

// ********************************************************************************
//
// ********************************************************************************
void CBaseEntity::update(float fDelta)
{
}

// ********************************************************************************
//
// ********************************************************************************
bool CBaseEntity::manageEvent(TBaseEvent *pMessage)
{
	return false;
}

// ********************************************************************************
//
// ********************************************************************************
void CBaseEntity::freeResources()
{
	removedFromScene();
	if (m_pSpriteInfo)
	{
		ISpritesFactory::get()->releaseSprite(m_pSpriteInfo);
		m_pSpriteInfo = NULL;
	}
}

// ********************************************************************************
//
// ********************************************************************************
ISpritesFactory::TSpriteInfo *CBaseEntity::getDefaultSprite()
{
	return m_pSpriteInfo;
}

const rapidjson::Value *	CBaseEntity::getInfo() { return m_pInfo; }