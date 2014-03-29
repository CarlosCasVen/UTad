#ifndef __SOUND_MANAGER__
#define __SOUND_MANAGER__

#include "ISoundManager.h"

enum TError;

class SoundManager : public ISoundManager
{
public:
    virtual TError  Init();
	virtual void    End ();

    virtual void PlaySample ( ISample* sample );
    virtual void StopSample ( ISample* sample );
    virtual void PauseSample( ISample* sample );

private:
    SoundManager ();
    ~SoundManager();

    friend class ISoundManager;
};


#endif