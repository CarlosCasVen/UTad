#ifndef __ISOUND_MANAGER__
#define __ISOUND_MANAGER__

enum TError;
class ISample;

class ISoundManager
{
public:
    static ISoundManager& Instance();

	virtual TError  Init()  = 0;
	virtual void    End ()  = 0;

    virtual void PlaySample ( ISample* sample ) = 0;
    virtual void StopSample ( ISample* sample ) = 0;
    virtual void PauseSample( ISample* sample ) = 0;
};


#endif