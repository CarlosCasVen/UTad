#ifndef __ISOUND_MANAGER__
#define __ISOUND_MANAGER__

enum TError;


class ISoundManager
{
public:
    static ISoundManager& Instance();

	virtual TError  Init()  = 0;
	virtual void    End ()  = 0;

//    virtual void PlaySound () = 0;
    virtual void StopSound () = 0;
    virtual void PauseSound() = 0;
};


#endif