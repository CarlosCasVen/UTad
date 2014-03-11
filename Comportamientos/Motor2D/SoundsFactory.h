#ifndef ___SOUNDFACTORY___
#define ___SOUNDFACTORY___

#include "ISoundsFactory.h"
#include "sounds/BaseSound.h"

class CSoundsFactory : public ISoundsFactory
{
public:
	virtual int  init();
	virtual void end ();

	virtual int			addInfo(const rapidjson::Value *pInfo);

	virtual ISound *getSound		(const char *pszName);
	virtual void		releaseSound(ISound *pSprite);

private:

	CSoundsFactory();
	~CSoundsFactory();

	ISound *createSoundWithInfo(const rapidjson::Value &info);

	CBaseSound::Type getSoundTypeByName(const char *pszName);

	const rapidjson::Value *m_pSoundsInfo;

	friend class ISoundsFactory;
};

#endif