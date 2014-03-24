#ifndef __BASE_ENTITY__
#define __BASE_ENTITY__

#include "IEntity.h"
#include "../json/rapidjson/document.h"

class IScene;
class IComponent;

class BaseEntity : public IEntity
{
public:
    BaseEntity( const rapidjson::Value& params );

    virtual TError Init();
    virtual void   End ();

    virtual void Update( double elapsedTime);

    virtual unsigned int GetId()							   const;
    virtual void         SetParentScene( const IScene* parentScene );

protected:
    const rapidjson::Value& GetParams      () const;
    const IScene*           GetParentScene ();
	virtual void            AddComponent   ( IComponent* component );
	virtual void            RemoveComponent( IComponent* component );

private:
    const rapidjson::Value* m_params;
    unsigned long int       m_id;
    const IScene*           m_scene; 
	Array<IComponent*>      m_components;

};

#endif