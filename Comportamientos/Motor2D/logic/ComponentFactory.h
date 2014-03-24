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

    virtual IComponent* GetComponent   ( const rapidjson::Value* componentInfo, TError& error );
    virtual void        RemoveComponent( IComponent* component)                                ;   

private:
    ComponentFactory ();
    ~ComponentFactory();

    TComponent GetTypeByName( const char* tName );

    Array<IComponent*> m_components;

    friend class IComponentFactory;
};

#endif