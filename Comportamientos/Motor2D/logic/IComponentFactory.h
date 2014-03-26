#ifndef __ICOMPONENT_FACTORY__
#define __ICOMPONENT_FACTORY__

#include "../json/rapidjson/document.h"

class IComponent;
enum  TError;

class IComponentFactory
{
public:
    static IComponentFactory& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual void RemoveComponent( IComponent* component) = 0;   

    template <typename T>
    T* GetComponent ( TError& error );

};


template <typename T>
T* IComponentFactory::GetComponent ( TError& error )
{
    T* newComponent = NEW( T, () );

    if( !newComponent ) error = ERROR;

    return newComponent;
}


#endif