#include "../stdafx.h"
#include "StreamSound.h"

// *****************************************************************************************
//
// *****************************************************************************************
CStreamSound::CStreamSound(const rapidjson::Value *pSoundInfo) : CBaseSound(CBaseSound::EStream, pSoundInfo)
{
	m_bPaused   = false;
	m_hStream		= 0;

	const rapidjson::Value *pInfo = getInfo();
	if (pInfo)
	{
		const char *pszFile = (*pInfo)["file"].GetString();
		if (pszFile)
			m_hStream = BASS_StreamCreateFile(FALSE, pszFile, 0, 0 , 0);
	}
}

// *****************************************************************************************
//
// *****************************************************************************************
CStreamSound::~CStreamSound()
{
	if (m_hStream)
	{
		BASS_StreamFree(m_hStream);
		m_hStream		= 0;
	}
}

// *****************************************************************************************
//
// *****************************************************************************************
void CStreamSound::doPlay(int from)
{
	if (m_bPaused)
		BASS_ChannelPlay(m_hStream, FALSE);
	else
		BASS_ChannelPlay(m_hStream, TRUE);
}

// *****************************************************************************************
//
// *****************************************************************************************
void CStreamSound::doStop()
{
	BASS_ChannelStop(m_hStream);
}

// *****************************************************************************************
//
// *****************************************************************************************
void CStreamSound::doPause()
{
	BASS_Pause();
	m_bPaused = true;
}
