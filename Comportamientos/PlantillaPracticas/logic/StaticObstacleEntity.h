#ifndef __STATIC_OBSTACLE_ENTITY__
#define __STATIC_OBSTACLE_ENTITY__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"



class StaticObstacleEntity : public BaseEntity
{
public:
    StaticObstacleEntity (  const rapidjson::Value* params );
    ~StaticObstacleEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

};


#endif