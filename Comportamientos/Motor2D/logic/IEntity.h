#ifndef __IBASE_ENTITY__
#define __IBASE_ENTITY__


enum TError;


class IEntity
{
public:
    virtual TError  Init() = 0;
    virtual void    End () = 0;

    virtual void Update( double ElpasedTime ) = 0;

};


#endif