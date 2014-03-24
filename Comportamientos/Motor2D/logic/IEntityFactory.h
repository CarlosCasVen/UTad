#ifndef __IENTITY_FACTORY__
#define __IENTITY_FACTORY__

#include "../json/rapidjson/document.h"

class IEntityFactory
{
public:
    enum TEntity
    {
        #define REG_ENTITY(val, name) \
		E##val,
        #include "ENTITY_TYPES.h"
        #undef REG_ENTITY
		// La última.
//        EPlayer,
		EInvalid,
    };
    static IEntityFactory& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual IEntity* GetEntity   ( const rapidjson::Value* entityInfo, TError& error ) = 0;
    virtual void     RemoveEntity( IEntity* entity )								   = 0;   

};

#endif
