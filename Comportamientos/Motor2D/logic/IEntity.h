#ifndef __IENTITY__
#define __IENTITY__


enum TError;
class IScene;

class IEntity
{
public:
    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual void   Update( double elapsedTime) = 0;

    virtual unsigned int GetId         ()	                   const = 0;
    virtual void         SetParentScene( IScene* parentScene )       = 0;

    virtual IScene* GetParentScene () const = 0;

};


#endif