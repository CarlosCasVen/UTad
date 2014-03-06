#ifndef __EVENT_MANAGER__
#define __EVENT_MANAGER__

#include <stdio.h>
#include "../include/array.h"

enum TEvent;
class BaseEntity;
class Event;

struct EventSubscriptors
{
	enum TEvent type;
	Array<BaseEntity*> subscriptors;
};

class EventManager
{
public:
	static EventManager& Instance();
	void Update( double elapsedTime );
	void SendEvent ( Event& event, Array<BaseEntity*>& subscriptors );

private:
	EventManager();
	~EventManager();

	static EventManager* m_eventManager;
	Array<EventSubscriptors> m_eventsSubscriptors;
	Array<Event*> m_eventsRegistred;
};

#endif
