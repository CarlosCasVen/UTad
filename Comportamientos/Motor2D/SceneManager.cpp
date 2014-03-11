#include "stdafx.h"
#include "SceneManager.h"
#include "scenes/MenuScene.h"
#include "Utils/json.h"

CSceneManager *g_SM = NULL;

const char *MENU_SCENE_FILE = "data/scenes/menu_scene.json";

// *************************************************************************************
//
// *************************************************************************************
ISceneManager *ISceneManager::get()
{
	if (!g_SM)
		g_SM = NEW(CSceneManager, ());

	return g_SM;
}

// *************************************************************************************
// Constructor
// *************************************************************************************
CSceneManager::CSceneManager()
{
	m_pCurrScene	= NULL;
	m_pszJSON			= NULL;
}
CSceneManager::~CSceneManager()
{
}

// *************************************************************************************
// Inicilización
// *************************************************************************************
int CSceneManager::init()
{
	int iRet = RET_ERR;

	if (loadJSON(MENU_SCENE_FILE, m_pszJSON, m_docJSON))
	{
		m_pCurrScene = NEW(CMenuScene, (&m_docJSON));
		ASSERT(m_pCurrScene);
		if (m_pCurrScene)
			m_pCurrScene->init();
		iRet = RET_OK;
	}else
		ASSERT(0);

	return iRet;
}

// *************************************************************************************
// destrucción
// *************************************************************************************
void CSceneManager::end()
{
	SAFE_DELETE(m_pCurrScene);
	SAFE_DELETE_ARRAY(m_pszJSON);
	SAFE_DELETE(g_SM);
}

// *************************************************************************************
//
// *************************************************************************************
void CSceneManager::update(float fDelta)
{
	if (m_pCurrScene)
		m_pCurrScene->update(fDelta);
}

// *************************************************************************************
//
// *************************************************************************************
void CSceneManager::render(float fDelta)
{
	if (m_pCurrScene)
		m_pCurrScene->render(fDelta);
}

// *************************************************************************************
//
// *************************************************************************************
void CSceneManager::setNextScene()
{
}

// *************************************************************************************
//
// *************************************************************************************
void CSceneManager::prevNextScene()
{
}

// *************************************************************************************
//
// *************************************************************************************
void CSceneManager::setScene(IScene::TScene nScene)
{
}