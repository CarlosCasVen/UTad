#ifndef __BASEEVENT___
#define __BASEEVENT___

struct TBaseEvent
{
	enum TType
	{
		EMouseLeftButtomDown,
		EKeyboardKeyDown,
		EKeyboardKeyUp,
	};

	TBaseEvent(TType nType) { m_Type = nType; }

	TType m_Type;
};

#endif