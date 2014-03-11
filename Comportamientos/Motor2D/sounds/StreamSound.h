#ifndef ____STREAMSOUND____
#define ____STREAMSOUND____

#include "BaseSound.h"
#include "../bass/bass.h"

class CStreamSound : public CBaseSound
{
public:
	CStreamSound (const rapidjson::Value *pInfo);
	~CStreamSound();

		// Acciones de reprodución, llamadas desde el Sound Manager
	virtual void doPlay	(int from = CONTINUE);
	virtual void doStop	();
	virtual void doPause();

private:
	HSTREAM	m_hStream;

	bool m_bPaused;
};

#endif