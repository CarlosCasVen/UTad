#ifndef __ENTITY_FACTORY__
#define __ENTITY_FACTORY__

#include "IEntityFactory.h"
#include "../json/rapidjson/document.h"

enum TError;

class EntityFactory : public IEntityFactory
{
public:
    virtual TError Init();
    virtual void   End ();

    virtual IEntity* GetEntity   ( const rapidjson::Value* entityInfo, TError& error );
    virtual void     RemoveEntity( IEntity* entity);  
    
private:
    EntityFactory ();
    ~EntityFactory();

    TEntity GetTypeByName( const char* typeName );

    Array<IEntity*> m_entities;

    friend class IEntityFactory;
};


#endif