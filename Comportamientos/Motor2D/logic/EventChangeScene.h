#ifndef __EVENT_CHANGE_SCENE__
#define __EVENT_CHANGE_SCENE__


#include "Event.h"

class EventChangeScene : public Event
{
public:
	EventChangeScene( unsigned int index );
	~EventChangeScene();
    
	unsigned int GetIndexNextScene() const;

private:
	enum TEvent  m_type;
	unsigned int m_index;

};

#endif