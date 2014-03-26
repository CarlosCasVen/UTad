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
 /*       #define REG_COMPONENTS(val, name) \
		E##val,
        #include "COMPONENT_TYPES.h"
        #undef REG_COMPONENTS
		// La última.*/
        EBase,
        EBound,
        EInput,
        ELive,
        EMove,
        ESprite,
		EInvalid,
    };
    
    virtual TError Init() = 0;
	virtual void   End () = 0;

	virtual void Update( double elapsedTime ) = 0;

	virtual unsigned long int GetId	   ()		   const   = 0;
	virtual void			  SetParent( IEntity* entity ) = 0; 
    virtual IComponent::TComponent        GetType  ()		   const   = 0;
};


#endif __ICOMPONENT__
