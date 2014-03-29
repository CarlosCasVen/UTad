#ifndef __SHOOT_COMPONENT__
#define __SHOOT_COMPONENT__

#include "BaseComponent.h"
#include "../json/rapidjson/document.h"

class Event;
enum  TEvent;

class ShootComponent : public BaseComponent
{
public:
    ShootComponent ( const rapidjson::Value& params );
	~ShootComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    bool newBullet();

private:
    bool m_newBullet;

};

#endif