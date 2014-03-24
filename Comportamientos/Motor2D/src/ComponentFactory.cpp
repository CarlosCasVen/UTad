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
    m_components.Clear();
    DEL(m_componentFactory);
}

//-------------------------------------
//
//-------------------------------------
 IComponent* ComponentFactory::GetComponent ( const rapidjson::Value* componentInfo, TError& error )
 {
     if( !componentInfo->HasMember("Component") || !componentInfo->HasMember("Params") ) 
     {
        error = ERROR;
        return NULL;
     }

     IComponent* newComponent = NULL;
     TComponent type = GetTypeByName( (*componentInfo)["Component"].GetString() );
     const rapidjson::Value* param = &(*componentInfo)["Params"];

     switch (type)
	 {
#define REG_COMPONENT(val, name) \
		case E##val: \
		  newComponent = NEW(val##Component,(*param)); \
          m_components.Add( newComponent ); \
		  break;
#include "../logic/COMPONENT_TYPES.h"
#undef REG_COMPONENT
		default:
            error = ERROR;
			break;
	}
   
    return newComponent;
 }
  
 //-------------------------------------
//
//-------------------------------------
 void ComponentFactory::RemoveComponent( IComponent* component)
 {
     if( component ) m_components.Remove( component );
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

//-------------------------------------
//
//-------------------------------------
 IComponentFactory::TComponent ComponentFactory::GetTypeByName( const char* tName)
{
     TComponent type = EInvalid;

#define REG_COMPONENT(val, name) \
    if( strcmp( tName, name ) == 0 ) \
    type = E##val;  
#include "../logic/COMPONENT_TYPES.h"
#undef REG_COMPONENT
	return type;
 }