#include "stdafx.h"
#include "SoundsFactory.h"
#include "include/image.h"
#include "sounds/PreloadedSound.h"
#include "sounds/StreamSound.h"

ISoundsFactory *g_SF = NULL;

ISoundsFactory * ISoundsFactory::get()
{
	if (!g_SF)
		g_SF = NEW(CSoundsFactory, ());

	return g_SF;
}

CSoundsFactory::CSoundsFactory()
{
	m_pSoundsInfo	= NULL;
}

// **********************************************************************************
//
// **********************************************************************************
int CSoundsFactory::init()
{
	return RET_OK;
}

// **********************************************************************************
//
// **********************************************************************************
void CSoundsFactory::end()
{
	SAFE_DELETE(g_SF);
}

// **********************************************************************************
//
// **********************************************************************************
int	CSoundsFactory::addInfo(const rapidjson::Value *pInfo)
{
	if (pInfo)
		m_pSoundsInfo	= &(*pInfo)["sounds"];

	return 0;
}

// **********************************************************************************
//
// **********************************************************************************
ISound *CSoundsFactory::getSound(const char *pszName)
{
	ISound *pRet = NULL;

	if (m_pSoundsInfo && pszName)
	{
		int i						= 0;
		int iNumSounds = (*m_pSoundsInfo).Size();
		while (!pRet  && (i < iNumSounds))
		{
			const rapidjson::Value &currSoundInfo = (*m_pSoundsInfo)[i];
			if (!strcmp(pszName, currSoundInfo["name"].GetString()))
				pRet = createSoundWithInfo(currSoundInfo);
			else
				i++;
		}
	}

	return pRet;
}

// **********************************************************************************
//
// **********************************************************************************
void CSoundsFactory::releaseSound(ISound *pSound)
{
	if (pSound)
		DEL(pSound);
}

// **********************************************************************************
//
// **********************************************************************************
ISound *CSoundsFactory::createSoundWithInfo(const rapidjson::Value &info)
{
	ISound *pRet = NULL;

	CBaseSound::Type nSoundType = getSoundTypeByName(info["type"].GetString());
	switch(nSoundType)
	{
		case CBaseSound::EPreloaded:
			pRet = NEW(CPreloadedSound, (&info));
			break;
		case CBaseSound::EStream:
			pRet = NEW(CStreamSound, (&info));
			break;
		default:
			break;
	}

	return pRet;
}

// **********************************************************************************
//
// **********************************************************************************
CBaseSound::Type CSoundsFactory::getSoundTypeByName(const char *pszName)
{
	CBaseSound::Type nRet = CBaseSound::EInvalid;

	if (pszName)
	{
		if			(!strcmp(pszName, "preloaded"))
			nRet = CBaseSound::EPreloaded;
		else if (!strcmp(pszName, "stream"))
			nRet = CBaseSound::EStream;
	}

	return nRet;
}