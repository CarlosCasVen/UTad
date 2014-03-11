#include "../stdafx.h"
#include "ButtonEntity.h"
#include "../IEventsManager.h"
#include "../include/sprite.h"
#include "../ISoundsFactory.h"
#include "../ISound.h"
#include "../events/MouseEvents.h"

CButtonEntity::CButtonEntity(unsigned int uId, const rapidjson::Value *pInfo) : CBaseEntity(IEntitiesFactory::EButton, uId, pInfo)
{
}

int CButtonEntity::addedToScene(CBaseScene *pScene)
{
	CBaseEntity::addedToScene(pScene);
	IEventsManager::get()->registerToEvents(this, 0);

	m_pSound = ISoundsFactory::get()->getSound("explosion");

	return RET_OK;
};

void CButtonEntity::removedFromScene()
{
	CBaseEntity::removedFromScene();
	IEventsManager::get()->unregisterToEvents(this);
}

bool CButtonEntity::manageEvent(TBaseEvent *pMessage)
{
	bool bRet = false;

	CBaseEntity::manageEvent(pMessage);
	if (pMessage->m_Type == TBaseEvent::EMouseLeftButtomDown)
	{
		getDefaultSprite()->m_pSprite->SetScale(2.0f, 2.0f);
		if (m_pSound) m_pSound->play();
		bRet = true;
	}

	return bRet;
}