#ifndef ___BASESOUND___
#define ___BASESOUND___

#include "../ISound.h"
#include "../Utils/rapidjson/document.h"

class CBaseSound : public ISound
{
public:

	enum Type
	{
		EPreloaded,
		EStream,

		EInvalid,
	};

	// Peticiones de reproducción, llamdas desde la lógica.
	virtual void play	(int from = CONTINUE);
	virtual void stop	();
	virtual void pause();

	// Acciones de reprodución, llamadas desde el Sound Manager
	virtual void doPlay	(int from = CONTINUE) = 0;
	virtual void doStop	()										= 0;
	virtual void doPause()										= 0;

	Type getType();

protected:
	CBaseSound(Type nType, const rapidjson::Value *pInfo);
	virtual ~CBaseSound();

	const rapidjson::Value *getInfo();

private:
	Type m_nType;

	const rapidjson::Value *m_pInfo;

	friend class CSoundsFactory;
};

#endif