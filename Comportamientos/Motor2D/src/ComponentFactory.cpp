#include "../logic/logic.h"

IComponentFactory* m_componentFactory = NULL;

//-------------------------------------
//
//-------------------------------------
IComponentFactory& IComponentFactory::Instance()
{
    if( !m_componentFactory ) m_componentFactory = NEW(ComponentFactory,());

    return *m_componentFactory;
}

//-------------------------------------
//
//-------------------------------------
TError ComponentFactory::Init()
{
    return OK;
}

//-------------------------------------
//
//-------------------------------------
void ComponentFactory::End()
{
    DEL(m_componentFactory);
}

 //-------------------------------------
//
//-------------------------------------
 void ComponentFactory::RemoveComponent( IComponent* component)
 {
     if( component ) DEL( component );
 }

//-------------------------------------
//
//-------------------------------------
 ComponentFactory::ComponentFactory()
 {
     
 }
  
//-------------------------------------
//
//-------------------------------------
 ComponentFactory::~ComponentFactory()
 {
 }
