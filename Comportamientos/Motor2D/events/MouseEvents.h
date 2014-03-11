#ifndef __MOUSEEVENTS__
#define __MOUSEEVENTS__

#include "BaseEvent.h"

struct TMouseEvent : TBaseEvent
{
	float m_fPosX;
	float m_fPosY;
	TMouseEvent(TBaseEvent::TType nType, float fPosX, float fPosY) : TBaseEvent(nType)
	{
		m_fPosX = fPosX;
		m_fPosX = fPosY;
	}
};

#endif