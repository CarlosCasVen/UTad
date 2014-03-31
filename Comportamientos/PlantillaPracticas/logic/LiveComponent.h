#ifndef __LIVE_COMPONENT__
#define __LIVE_COMPONENT__

#include "BaseComponent.h"
#include "IListener.h"
#include "../json/rapidjson/document.h"


class Event;
enum  TEvent;


class LiveComponent : public BaseComponent
{
public:
    LiveComponent ();
	~LiveComponent();

	virtual TError Init();
	virtual void   End ();

	virtual void Update( double elapsedTime );

    void         SetLive( unsigned int live );
    unsigned int GetLive()              const;

	void SubstractLive( unsigned int damage );

private:
    unsigned int m_live;

};

#endif