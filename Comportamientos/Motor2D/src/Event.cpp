#include "../logic/Logic.h"


//-------------------------------------
//
//-------------------------------------
Event::Event( TEvent tEvent )
{
    m_type = tEvent;
}

//-------------------------------------
//
//-------------------------------------
TEvent Event::GetType() const
{
    return m_type;
}