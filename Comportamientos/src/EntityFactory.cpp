#include "../logic/Logic.h"


EntityFactory* m_entityFactory = NULL;


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
    DEL( m_entityFactory );
}

//-------------------------------------
//
//-------------------------------------
Array<IEntity*>& EntityFactory::CreateEntities( const String* path )
{
    String content = String::Read( path->ToCString() );
    rapidjson::Document document;
    document.Parse<0>( content.ToCString() );

    if( document.HasParseError() )
    {
        return;
    }

    const rapidjson::Value& entities = document["Entities"];    

    for( unsigned int i = 0; i < entities.Size(); i++ )
    {
        const rapidjson::Value& entity = entities[ "Entity" ];
        const rapidjson::Value& params = entities[ "Params" ];
    }

    return m_entities;
}

//-------------------------------------
//
//-------------------------------------
IEntity* EntityFactory::CreateEntity( TEntity type, TError& error, const rapidjson::Value& params )
{
    IEntity* newEntity = NULL;

    switch( type )
    {
    case '0':
        error = OK;
        break;
    default:
        error = NO_ENTITY_TYPE;
    }

    return newEntity;
}