#ifndef __ICOMPONENT__
#define __ICOMPONENT__


enum TError;
class IEntity;
enum TComponent;


class IComponent
{
public:
    enum TComponent
    {
        EBase,
        EBound,
        EInput,
        ELive,
        EMove,
        ESprite,
        ECollision,
        EDamage,
        EAnimator,
        ELabel,
        EInvalid,
    };
    
    virtual TError Init() = 0;
	virtual void   End () = 0;

	virtual void Update( double elapsedTime ) = 0;

	virtual unsigned long int       GetId	   ()		   const = 0;
	virtual void			        SetParent( IEntity* entity ) = 0; 
    virtual IComponent::TComponent  GetType  ()		       const = 0;
    virtual IEntity*                GetParent()                  = 0;
};


#endif __ICOMPONENT__
