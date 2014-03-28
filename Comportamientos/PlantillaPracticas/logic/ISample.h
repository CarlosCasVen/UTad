#ifndef __ISAMPLE__
#define __ISAMPLE__


enum TError;


class ISample
{
public:
    enum TSample
    {
        EStream,
        ELoaded,
        EInvalid,
    };
    
    virtual TError Init() = 0;
	virtual void   End () = 0;

	virtual unsigned long int       GetId	 ()		       const = 0;
    virtual TSample                 GetType  ()		       const = 0;

    virtual void PlaySample ()            = 0;
    virtual void PauseSample()            = 0;
    virtual void StopSample ()            = 0;
};


#endif __ISAMPLE__
