#ifndef __IENTITY_FACTORY__
#define __IENTITY_FACTORY__


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
		EInvalid,
    };
    static IEntityFactory& Instance();

    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual Array<IEntity*>& CreateEntities( const String* path, TError& error ) = 0;

};

#endif
