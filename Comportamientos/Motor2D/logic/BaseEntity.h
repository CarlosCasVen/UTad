#ifndef __BASE_ENTITY__
#define __BASE_ENTITY__

#include "IEntity.h"


class Sprite;
class BaseScene;
class IScene;


class BaseEntity : public IEntity, IListener
{
public:
	BaseEntity( const rapidjson::Value& params );

    virtual TError Init( IScene* m_scene );
    virtual void   End ();

    virtual void Update( double ElpasedTime ) = 0;

    virtual unsigned long int GetId    () const;
    virtual Sprite*           GetSprite() const;   
	virtual void			  SetScene ( IScene& scene );	

    virtual void              ReceiveEvent ( Event& newEvent ) = 0;
    virtual unsigned long int GetListenerId()                const;

protected:
    virtual void			  SetSprite( Sprite* sprite );
    virtual Sprite*			  GetSprite();
	virtual const rapidjson::Value& GetParams();

private:
	const rapidjson::Value* m_params;
	Sprite*					m_sprite;
	IScene*					m_baseScene;
    unsigned long int		m_id;

};


#endif