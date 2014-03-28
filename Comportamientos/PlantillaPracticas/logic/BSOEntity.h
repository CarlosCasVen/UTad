#ifndef __BSO_ENTITY__
#define __BSO_ENTITY__

#include "BaseEntity.h"
#include "../json/rapidjson/document.h"

class ISample;
enum TError;

class BSOEntity : public BaseEntity
{
public:
    BSOEntity (  const rapidjson::Value* params );
    ~BSOEntity();

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime );

private:
    ISample* m_sample;
};


#endif