#include "../stdafx.h"
#include "BaseSound.h"
#include "../ISoundsManager.h"

// *****************************************************************************************
//
// *****************************************************************************************
CBaseSound::CBaseSound(Type nType, const rapidjson::Value *pInfo)
{
	m_nType = nType;
	m_pInfo	= pInfo;
}

// *****************************************************************************************
//
// *****************************************************************************************
CBaseSound::~CBaseSound()
{
}

// *****************************************************************************************
// PUBLIC: Petici�n de la l�gica de hacer play del audio
// *****************************************************************************************
void CBaseSound::play(int iFrom)
{
	// Le indicamos al gestor de sonidos que queremos hacer play del esta audio.
	ISoundsManager::get()->playSound(this);
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseSound::stop()
{
	ISoundsManager::get()->stopSound(this);
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseSound::pause()
{
	ISoundsManager::get()->plauseSound(this);
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseSound::doPlay(int iFrom)
{
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseSound::doStop()
{
}

// *****************************************************************************************
//
// *****************************************************************************************
void CBaseSound::doPause()
{
}

// *****************************************************************************************
// GETTERS
// *****************************************************************************************
CBaseSound::Type				CBaseSound::getType() { return m_nType; }
const rapidjson::Value *CBaseSound::getInfo()	{ return m_pInfo; }