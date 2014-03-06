#include "../logic/Logic.h"


Event::Event( TEvent tEvent )
{
	m_tEvent = tEvent;
}


Event::~Event()
{
}


TEvent Event::GetTEvent() const
{
	return m_tEvent;
}