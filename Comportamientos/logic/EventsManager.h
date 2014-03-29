#include <stdio.h>


class EventManager
{
public:
	EventManager& Instance(){  if( m_eventManager == NULL ) m_eventManager = new EventManager(); return *m_eventManager; }

private:
	EventManager(){ m_eventManager = NULL; }

	EventManager* m_eventManager;

};
