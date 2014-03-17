#include "../logic/Logic.h"
#include "../include/u-gine.h"


EntityFactory* m_entityFactory = NULL;

//-------------------------------------
//
//-------------------------------------
EntityFactory::EntityFactory()
{
}
 
//-------------------------------------
//
//-------------------------------------
EntityFactory::~EntityFactory()
{
}

//-------------------------------------
//
//-------------------------------------
IEntityFactory& IEntityFactory::Instance()
{
    if( !m_entityFactory ) m_entityFactory = NEW( EntityFactory, () );

    return *m_entityFactory;
}

//-------------------------------------
//
//-------------------------------------
TError EntityFactory::Init()
{
    TError error = OK;

    return error;
}

//-------------------------------------
//
//-------------------------------------
void EntityFactory::End()
{
    m_entities.Clear();
    DEL( m_entityFactory );
}

//-------------------------------------
//
//-------------------------------------
IEntity* EntityFactory::GetEntity( const rapidjson::Value* entityInfo, TError& error )
{
    if( !entityInfo->HasMember("Entity") || !entityInfo->HasMember("Params") ) 
    {
        error = ERROR;
        return NULL;
    }

    IEntity* newEntity = NULL;
    TEntity type = GetTypeByName( (*entityInfo)["Entity"].GetString() );
    const rapidjson::Value* param = &(*entityInfo)["Params"];

//    PlayerEntity( *param );
    switch (type)
	{
/*#define REG_ENTITY(val, name) \
		case E##val: \
        newEntity = NEW(val##Entity, ( *param ) ); \ 
        m_entities.Add( newEntity ); \
		  break;
#include "../logic/ENTITY_TYPES.h"
#undef REG_ENTITY*/
    case EPlayer:
        newEntity = NEW(PlayerEntity, ( *param ) ); 
        m_entities.Add( newEntity ); 
		  break;
		default:
            error = ERROR;
			break;
	}
   
    return newEntity;
}

//-------------------------------------
//
//-------------------------------------
IEntityFactory::TEntity EntityFactory::GetTypeByName( const char* typeName )
{
    TEntity type = EInvalid;

/*#define REG_ENTITY(val, name) \
    if( strcmp( typeName, name ) == 0 ) \
    type = E##val; \ 
#include "../logic/ENTITY_TYPES.h"
#undef REG_ENTITY
*/
    if( strcmp( typeName, "EPlayer" ) == 0 ) \
    type = EPlayer;
    return type;
}


void EntityFactory::RemoveEntity( IEntity* entity)
{
    if( entity ) m_entities.Remove( entity );
}