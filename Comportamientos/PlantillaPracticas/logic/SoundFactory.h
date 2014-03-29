#ifndef __SOUND_FACTORY__
#define __SOUND_FACTORY__

#include "ISoundFactory.h"

class SoundFactory : public ISoundFactory
{
public:
	virtual TError Init();
    virtual void   End ();

    virtual ISample* CreateSample( ISample::TSample type, const String* sample, TError& error );
    virtual void     RemoveSample( ISample* sample);   

private:
	SoundFactory ();
    ~SoundFactory();

    friend class ISoundFactory;
};

#endif
