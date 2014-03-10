#ifndef __ENTITY_FACTORY__
#define __ENTITY_FACTORY__

#include "IEntityFactory.h"
#include "../json/rapidjson/document.h"

enum TError;


class EntityFactory : public IEntityFactory
{
public:
    virtual TError Init() = 0;
    virtual void   End () = 0;

    virtual TError GetEntity()      = 0;

private:
    unsigned long int m_entityId;
    
};


#endif