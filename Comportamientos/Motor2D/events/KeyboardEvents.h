#ifndef __KEYBOARDEVENTS__
#define __KEYBOARDEVENTS__

#include "BaseEvent.h"

struct TKeyboardEvent : TBaseEvent
{
	int		m_iKeyId;
	TKeyboardEvent(TBaseEvent::TType nType, int iKey) : TBaseEvent(nType)
	{
		m_iKeyId		= iKey;
	}
};

#endif