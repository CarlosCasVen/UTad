#ifndef ___SOUNDMANAGER___
#define ___SOUNDMANAGER___

#include "ISoundsManager.h"

class CSoundsManager : public ISoundsManager
{
public:
	virtual int  init();
	virtual void end ();

	virtual void playSound	(ISound *pSound, int iFrom = ISound::CONTINUE);
	virtual void plauseSound(ISound *pSound);
	virtual void stopSound	(ISound *pSound);

	virtual void pauseAllSounds	();
	virtual void resumeAllSounds();
	virtual void stopAllSounds	();

private:

	CSoundsManager();
	~CSoundsManager();

	friend class ISoundsManager;
};
#endif