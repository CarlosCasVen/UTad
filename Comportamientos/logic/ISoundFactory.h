#ifndef __ISOUND_FACTORY__
#define __ISOUND_FACTORY__

#include "../json/rapidjson/document.h"
#include "ISample.h"


class String;
enum  TError;

class ISoundFactory
{
public:
    static ISoundFactory& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual ISample* CreateSample( ISample::TSample type, const String* sample, TError& error ) = 0;
    virtual void     RemoveSample( ISample* sample)                                             = 0;   

};



#endif