#ifndef __LIVE_COMPONENT__
#define __LIVE_COMPONENT__

#include "BaseComponent.h"
#include "IListener.h"
#include "../json/rapidjson/document.h"


class Event;
enum  TEvent;


class LiveComponent : public BaseComponent, IListener
{
public:
    LiveComponent ();
	~LiveComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    virtual void SetLive( unsigned int live );

    virtual void              ReceiveEvent ( Event& newEvent );
    virtual unsigned long int GetListenerId()            const;

private:
     void SubstractLive( unsigned int damage );

    unsigned int m_live;

};

#endif