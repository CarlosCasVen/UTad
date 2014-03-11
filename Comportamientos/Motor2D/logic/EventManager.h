#ifndef __EVENT_MANAGER__
#define __EVENT_MANAGER__

#include "IEventManager.h"


enum  TEvent;
class IBaseEntity;
class Event;
class IListener;


struct Subscriptors
{
	enum TEvent       m_type;
	Array<IListener*> m_subscriptors;
};


class EventManager : public IEventManager
{
public:
	virtual TError  Init();
	virtual void    End ();

	virtual void Update();

    virtual TError RegistreToEvent   ( IListener& subscriptor, TEvent& tEvent );
	virtual TError UnregistredToEvent( TEvent& tEvent, IListener& subscriptor );

private:
    void ComunicateSubscriptors( Event& newEvent, Array<IListener*> subscriptors );
    
    Array<Subscriptors*> m_subscriptors;
    Array<Event*>        m_eventsRegistred;

};


#endif
