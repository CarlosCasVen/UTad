#include "../logic/Logic.h"


EventManager* EventManager::m_eventManager = NULL;

EventManager& EventManager::Instance()
{
	if( !m_eventManager )
	{
		m_eventManager = NEW( EventManager , );
	}

	return *m_eventManager;
}


void EventManager::Update( double elapsedTime )
{
	for( unsigned int i = 0; i < m_eventsRegistred.Size(); i++ )
	{
		for( unsigned int k  = 0; k < m_eventsSubscriptors.Size(); k++ )
		{
			if( m_eventsRegistred[i]->GetTEvent() == m_eventsSubscriptors[k].type )
			{
				SendEvent( *m_eventsRegistred[i], m_eventsSubscriptors[k].subscriptors );
			}
		}
	}
}


void SendEvent ( Event& event, Array<BaseEntity*>& subscriptors )
{
	for( unsigned int i = 0; i < subscriptors.Size(); i++ )
	{
		//subscriptors[i]->Send( event );
	}
}


EventManager::EventManager()
{

}


EventManager::~EventManager()
{

}