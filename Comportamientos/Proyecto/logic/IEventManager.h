#ifndef __IEVENT_MANAGER__
#define __IEVENT_MANAGER__


enum TEvent;
class Event;
class IListener;


class IEventManager
{
public:
    static IEventManager& Instance();

	virtual TError  Init()  = 0;
	virtual void    End ()  = 0;

	virtual void Update() = 0;

    virtual TError RegistreToEvent   ( IListener& subscriptor, TEvent& tEvent )   = 0;
	virtual TError UnregistredToEvent( TEvent& tEvent, IListener& subscriptor )   = 0;

    virtual void AddEvent( Event& newEvent ) = 0;

};


#endif