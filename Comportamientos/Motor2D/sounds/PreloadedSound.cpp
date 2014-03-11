#include "../stdafx.h"
#include "PreloadedSound.h"

// *****************************************************************************************
//
// *****************************************************************************************
CPreloadedSound::CPreloadedSound(const rapidjson::Value *pSoundInfo) : CBaseSound(CBaseSound::EPreloaded, pSoundInfo)
{
	m_bPaused   = false;
	m_hSample		= 0;
	m_hChannel	= 0;

	const rapidjson::Value *pInfo = getInfo();
	if (pInfo)
	{
		const char *pszFile = (*pInfo)["file"].GetString();
		if (pszFile)
			m_hSample = BASS_SampleLoad(FALSE, pszFile, 0, 0, 3, 0);
	}
}

// *****************************************************************************************
//
// *****************************************************************************************
CPreloadedSound::~CPreloadedSound()
{
	if (m_hSample)
	{
		BASS_SampleFree(m_hSample);
		m_hSample		= 0;
		m_hChannel	= 0;
	}
}

// *****************************************************************************************
//
// *****************************************************************************************
void CPreloadedSound::doPlay(int from)
{
	if (checkValidChannel())
	{
		if (m_bPaused)
			BASS_Start();
		else
			BASS_ChannelPlay(m_hChannel, TRUE);
	}else
	{
		m_hChannel = BASS_SampleGetChannel(m_hSample, FALSE);
		BASS_ChannelPlay(m_hChannel, FALSE);
	}
}

// *****************************************************************************************
//
// *****************************************************************************************
void CPreloadedSound::doStop()
{
	BASS_Stop();
}

// *****************************************************************************************
//
// *****************************************************************************************
void CPreloadedSound::doPause()
{
	if (checkValidChannel() && (BASS_ChannelIsActive(m_hChannel) == BASS_ACTIVE_PLAYING))
	{
		BASS_Pause();
		m_bPaused = true;
	}
}

// *****************************************************************************************
//
// *****************************************************************************************
bool CPreloadedSound::checkValidChannel()
{
	bool bRet = false;
	if (m_hChannel)
	{
		BASS_CHANNELINFO info;
		BASS_ChannelGetInfo(m_hChannel, &info);
		if (info.sample == m_hSample)
			bRet = true;
		else
			m_hChannel = 0;
	}

	return bRet;
}