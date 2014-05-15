#ifndef __DYNAMIC_OBSTACLE_ENTITY__
#define __DYNAMIC_OBSTACLE_ENTITY__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"



class DynamicObstacleEntity : public BaseEntity
{
public:
    DynamicObstacleEntity(  const rapidjson::Value* params );
    ~DynamicObstacleEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

};


#endif