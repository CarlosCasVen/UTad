#ifndef __ICOMPONENT_FACTORY__
#define __ICOMPONENT_FACTORY__

#include "../json/rapidjson/document.h"

class IComponent;
enum  TError;

class IComponentFactory
{
public:
    enum TComponent
    {
        #define REG_COMPONENT(val, name) \
		E##val,
        #include "COMPONENT_TYPES.h"
        #undef REG_COMPONENT
		// La última.
		EInvalid,
    };

    static IComponentFactory& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual IComponent* GetComponent   ( const rapidjson::Value* componentInfo, TError& error ) = 0;
    virtual void        RemoveComponent( IComponent* component)                                 = 0;   

};

#endif