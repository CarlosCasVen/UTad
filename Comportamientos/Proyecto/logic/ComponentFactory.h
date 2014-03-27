#ifndef __COMPONENT_FACTORY__
#define __COMPONENT_FACTORY__

#include "../include/array.h"
#include "IComponentFactory.h"
#include "../json/rapidjson/document.h"

class IComponent;
enum  TError;
enum  TComponent;

class ComponentFactory : public IComponentFactory
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual void        RemoveComponent( IComponent* component)                                ;   

private:
    ComponentFactory ();
    ~ComponentFactory();


    friend class IComponentFactory;
};

#endif