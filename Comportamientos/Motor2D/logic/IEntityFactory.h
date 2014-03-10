#ifndef __IENTITY_FACTORY__
#define __IENTITY_FACTORY__


class IEntityFactory
{
public:
    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual TError GetEntity()      = 0;

};

#endif
