#ifndef __IIDFACTORY__
#define __IIDFACTORY__


class IIdFactory
{
public:
    static IIdFactory& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual unsigned long int GetId() = 0;
    
private:
    virtual unsigned long int GenerateId() = 0;

};


#endif