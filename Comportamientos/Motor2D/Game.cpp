#include "stdafx.h"
#include "Game.h"
#include "IEntitiesFactory.h"
#include "ISpritesFactory.h"
#include "ISceneManager.h"
#include "IEventsManager.h"
#include "ISoundsManager.h"
#include "ISoundsFactory.h"

IGame *g_pGame = NULL;

// ****************************************************************************************
//
// ****************************************************************************************
IGame *IGame::get()
{
	if (!g_pGame)
		g_pGame = NEW(CGame, ());

	return g_pGame;
}

// ****************************************************************************************
//
// ****************************************************************************************
int CGame::init()
{
	int iRet = RET_OK;

	if (iRet == RET_OK) iRet = ISpritesFactory::	get()->init();
	if (iRet == RET_OK) iRet = ISoundsFactory::		get()->init();
	if (iRet == RET_OK) iRet = ISoundsManager::		get()->init();
	if (iRet == RET_OK) iRet = IEventsManager::		get()->init();
	if (iRet == RET_OK) iRet = IEntitiesFactory:: get()->init();
	if (iRet == RET_OK) iRet = ISceneManager::		get()->init();

	return iRet;
}

// ****************************************************************************************
//
// ****************************************************************************************
void CGame::end ()
{
	ISceneManager::		get()->end();
	IEntitiesFactory::get()->end();
	IEventsManager::	get()->end();
	ISoundsManager::	get()->end();
	ISoundsFactory::	get()->end();
	ISpritesFactory::	get()->end();

	SAFE_DELETE(g_pGame);
}

// ****************************************************************************************
//
// ****************************************************************************************
void CGame::update(float fDelta)
{
	IEventsManager::get()->update();
	ISceneManager::	get()->update(fDelta);
}

// ****************************************************************************************
//
// ****************************************************************************************
void CGame::render(float fDelta)
{
	ISceneManager::get()->render(fDelta);
}


// ****************************************************************************************
//
// ****************************************************************************************
float CGame::getScaleX()
{
	return 1.0;
}

// ****************************************************************************************
//
// ****************************************************************************************
float CGame::getScaleY()
{
	return 1.0;
}