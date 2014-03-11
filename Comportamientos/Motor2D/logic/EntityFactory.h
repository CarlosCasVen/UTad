#ifndef __ENTITY_FACTORY__
#define __ENTITY_FACTORY__

#include "IEntityFactory.h"
#include "../json/rapidjson/document.h"

enum TError;
enum TEntity;

class EntityFactory : public IEntityFactory
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual Array<IEntity*>& CreateEntities( const String* path, TError& error );

private:
    IEntity* CreateEntity( TEntity type, TError& error, const rapidjson::Value& params );

    unsigned long int m_entityId;
    Array<IEntity*>   m_entities;
    
};


#endif