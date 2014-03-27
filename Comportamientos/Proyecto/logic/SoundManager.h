#ifndef __SOUND_MANAGER__
#define __SOUND_MANAGER__

#include "ISoundManager.h"

enum TError;

class SoundManager : public ISoundManager
{
public:
    virtual TError  Init();
	virtual void    End ();

 //   virtual void PlaySound ();
    virtual void StopSound ();
    virtual void PauseSound();

private:
    SoundManager ();
    ~SoundManager();

    friend class ISoundManager;
};


#endif