#ifndef __IDFACTORY__
#define __IDFACTORY__

#include "IIdFactory.h"


class IdFactory : public IIdFactory
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual unsigned long int GetId();
    
private:
    IdFactory ();
    ~IdFactory();

    virtual unsigned long int GenerateId();

    friend class IIdFactory;
};


#endif