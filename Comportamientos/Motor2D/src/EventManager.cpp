#include "../logic/Logic.h"


EventManager* m_eventManager = NULL;

//-------------------------------------
//
//-------------------------------------
IEventManager& IEventManager::Instance()
{
    if( m_eventManager == NULL ) m_eventManager = NEW( EventManager, () );

    return *m_eventManager;
}

//-------------------------------------
//
//-------------------------------------
TError EventManager::Init()
{
    TError error = OK;
    return error;
}

//-------------------------------------
//
//-------------------------------------
void EventManager::End()
{
    DEL( m_eventManager );
}

//-------------------------------------
//
//-------------------------------------
void EventManager::Update()
{
    for( unsigned int i = 0; i < m_eventsRegistred.Size(); i++ )
    {
        for( unsigned int k = 0; k < m_subscriptors.Size(); k++ )
        {
            if( m_eventsRegistred[i]->GetType() == m_subscriptors[k]->m_type )
            {
                ComunicateSubscriptors( *m_eventsRegistred[i], m_subscriptors[k]->m_subscriptors );
            }
        }
    }
}

 //-------------------------------------
//
//-------------------------------------
TError EventManager::RegistreToEvent( IListener& subscriptor, TEvent& tEvent )
{
    TError error = OK;
    bool foundTEvent = false;
    bool foundSubscriptor = false;
    unsigned int index = -1;

    for( unsigned int i = 0; i < m_subscriptors.Size() && !foundTEvent; i++ )
    {
        if( m_subscriptors[i]->m_type == tEvent )
        {
            foundTEvent = true;
            index = i;

            for( unsigned int k = 0; k < m_subscriptors[i]->m_subscriptors.Size() && !foundSubscriptor; k++ )
            {
                IListener* listener =  m_subscriptors[i]->m_subscriptors[k];
               
                if( listener->GetId() == subscriptor.GetId() )
                {
                    foundSubscriptor = true;
                }
            }
        }
    }

    if( !foundTEvent )          error = NO_EVENT;
    else if( foundSubscriptor ) error = LISTENER_REGISTRED;
    else                        m_subscriptors[index]->m_subscriptors.Add( &subscriptor );                

    
    return error;
}

//-------------------------------------
//
//-------------------------------------
TError EventManager::UnregistredToEvent( TEvent& tEvent, IListener& subscriptor )
{
    TError error = OK;
    bool foundTEvent = false;
    bool foundSubscriptor = false;

    for( unsigned int i = 0; i < m_subscriptors.Size() && !foundTEvent; i++ )
    {
        if( m_subscriptors[i]->m_type == tEvent )
        {
            foundTEvent = true;

            for( unsigned int k = 0; k < m_subscriptors[i]->m_subscriptors.Size() && !foundSubscriptor; k++ )
            {
                IListener* listener =  m_subscriptors[i]->m_subscriptors[k];
               
                if( listener->GetId() == subscriptor.GetId() )
                {
                    foundSubscriptor = true;
                    m_subscriptors[i]->m_subscriptors.RemoveAt( k );
                }
            }
        }
    }

    if( !foundTEvent )              error = NO_EVENT;
    else if( !foundSubscriptor )    error = LISTENER_NO_REGISTRED;
    
    return error;
}

//-------------------------------------
//
//-------------------------------------
void EventManager::ComunicateSubscriptors( Event& newEvent, Array<IListener*> subscriptors )
{
    for( unsigned int i = 0; i < subscriptors.Size(); i++ )
    {
        subscriptors[i]->ReceiveEvent( newEvent );
    }
}