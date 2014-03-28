#ifndef __IENTITY_FACTORY__
#define __IENTITY_FACTORY__

#include "../json/rapidjson/document.h"
#include "leaks.h"

enum TError;
class IEntity;

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

    virtual IEntity* GetEntity          ( const rapidjson::Value* entityInfo, TError& error ) = 0;
    virtual void     RemoveEntity       ( IEntity* entity )								      = 0;

    template <typename T>
    T* GetTemporalEntity  ( TError& error );

};


 template <typename T>
 T* IEntityFactory::GetTemporalEntity( TError& error )
 {
     T* newEnt = NEW( T,( NULL ));

     if( !newEnt ) error = ERROR;

     return newEnt;
 }

 #endif