#ifndef ____SOUNDSMANAGER____
#define ____SOUNDSMANAGER____

#include "ISound.h"
class ISoundsManager
{
public:

	static ISoundsManager *get();

	virtual int  init() = 0;
	virtual void end () = 0;

	virtual void playSound	(ISound *pSound, int iFrom = ISound::CONTINUE)	= 0;
	virtual void plauseSound(ISound *pSound)																= 0;
	virtual void stopSound	(ISound *pSound)																= 0;

	virtual void pauseAllSounds	() = 0;
	virtual void resumeAllSounds() = 0;
	virtual void stopAllSounds	() = 0;
};

#endif