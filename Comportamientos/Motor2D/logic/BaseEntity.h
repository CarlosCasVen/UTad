#ifndef __BASE_ENTITY__
#define __BASE_ENTITY__

#include "IEntity.h"
#include "../json/rapidjson/document.h"

class IScene;

class BaseEntity : public IEntity
{
public:
    BaseEntity( const rapidjson::Value& params );

    virtual TError Init()   = 0;
    virtual void   End ()   = 0;

    virtual void   Update( double elapsedTime) = 0;

    virtual unsigned int GetId() const;
    virtual void         SetParentScene( const IScene* parentScene );

protected:
    const rapidjson::Value& GetParams     () const;
    const IScene*           GetParentScene();

private:
    const rapidjson::Value* m_params;
    unsigned long int       m_id;
    const IScene*           m_scene; 

};

#endif