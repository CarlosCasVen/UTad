#ifndef ____PRELOADEDSOUND____
#define ____PRELOADEDSOUND____

#include "BaseSound.h"
#include "../bass/bass.h"

class CPreloadedSound : public CBaseSound
{
public:
	CPreloadedSound (const rapidjson::Value *pInfo);
	~CPreloadedSound();

		// Acciones de reprodución, llamadas desde el Sound Manager
	virtual void doPlay	(int from = CONTINUE);
	virtual void doStop	();
	virtual void doPause();

private:

	bool CPreloadedSound::checkValidChannel();

	HSAMPLE		m_hSample;
	HCHANNEL	m_hChannel;

	bool m_bPaused;
};

#endif