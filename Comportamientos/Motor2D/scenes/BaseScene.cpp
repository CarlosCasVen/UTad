#include "../stdafx.h"
#include "BaseScene.h"
#include "../include/scene.h"
#include "../IEntity.h"
#include "../IEntitiesFactory.h"
#include "../ISoundsFactory.h"

// *****************************************************************************************
// PORTECTED: Contructor
// *****************************************************************************************
CBaseScene::CBaseScene(TScene nType, rapidjson::Document* info) : m_pinfo(info)
{
	m_nType = nType;
}

// *****************************************************************************************
// PORTECTED: Destructor
// *****************************************************************************************
CBaseScene::~CBaseScene()
{
	for (unsigned int i = 0; i < m_aEntities.size(); i++)
		IEntitiesFactory::get()->releaseEntity(m_aEntities[i]);

	SAFE_DELETE(m_pRenderer);
}

// *****************************************************************************************
// PUBLIC: Carga la escena y la deja lista para ser ejecutada y renderizada
// *****************************************************************************************
int CBaseScene::init()
{
	ISpritesFactory::	get()->addInfo				(m_pinfo);
	ISoundsFactory::	get()->addInfo				(m_pinfo);
	IEntitiesFactory::get()->addClassesInfo	(m_pinfo);

	m_pRenderer = createRenderer();

	// Creamos las entidades.
	const rapidjson::Value& entities = (*m_pinfo)["entities"];
	int iNumEntities = entities.Size();
	for (int i = 0; i < iNumEntities; i++)
	{
		IEntity *pEntity = IEntitiesFactory::get()->getEntity(&entities[i]);
		m_aEntities.push_back(pEntity);
		pEntity->addedToScene(this);
	}

	return 0;
}

// *****************************************************************************************
//
// *****************************************************************************************
IScene::TScene CBaseScene::getType()
{
	return m_nType;
}

// **********************************************************************************************
// PUBLIC: activa/desactiva la escena haciendoque se pueda ejecutar y gestione mensajes y eventos
// **********************************************************************************************
bool CBaseScene::activate(bool bActivate)
{
	return bActivate;
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseScene::update(float fDelta)
{
	for (unsigned int i = 0; i < m_aEntities.size(); i++)
		m_aEntities[i]->update(fDelta);
}

// *****************************************************************************************
//
// *****************************************************************************************
int CBaseScene::addSprite(ISpritesFactory::TSpriteInfo *pSprite)
{
	int iRet = RET_ERR;
	if (m_pRenderer)
	{
		m_pRenderer->AddSprite(pSprite->m_pSprite, pSprite->m_nLayer);
		iRet = RET_OK;
	}
	
	return iRet;
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseScene::removeSprite	(ISpritesFactory::TSpriteInfo *pSprite)
{
	if (m_pRenderer)
		m_pRenderer->RemoveSprite(pSprite->m_pSprite, pSprite->m_nLayer);
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseScene::render(float fDelta)
{
	m_pRenderer->Render();
}

// *****************************************************************************************
//
// *****************************************************************************************
IEntity *	CBaseScene::getEntity(const char *pszId)
{
	return NULL;
}
IEntity *	CBaseScene::getEntity(unsigned int uId)
{
	return NULL;
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseScene::manageMessage(TMessage *pMessageInfo)
{
}
