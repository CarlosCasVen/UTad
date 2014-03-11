#include "../stdafx.h"
#include "PlayerControllerComponent.h"
#include "../IEventsManager.h"
#include "../events/KeyboardEvents.h"

#define KEY_LEFT  65
#define KEY_RIGHT 68
#define KEY_UP    87
#define KEY_DOWN  83

// *******************************************************************************
//
// *******************************************************************************
CPlayerControllerComponent::CPlayerControllerComponent(unsigned int uId, const rapidjson::Value *pInfo) :
	CBaseComponent(IComponentsFactory::EPlayerController, uId, pInfo)
{
	m_bLeftPressed	= false;
	m_bRightPressed	= false;
	m_bUpPressed		= false;
	m_bDownPressed	= false;
}

// *******************************************************************************
//
// *******************************************************************************
CPlayerControllerComponent::~CPlayerControllerComponent()
{
}

// *******************************************************************************
//
// *******************************************************************************
void CPlayerControllerComponent::update(float fDelta)
{
}

// *******************************************************************************
//
// *******************************************************************************
bool CPlayerControllerComponent::manageEvent(TBaseEvent *pMessage)
{
	bool bRet = false;
	
	if (pMessage)
	{
		switch(pMessage->m_Type)
		{
			case TBaseEvent::EKeyboardKeyUp:
				switch  (reinterpret_cast<TKeyboardEvent *>(pMessage)->m_iKeyId)
				{
					case KEY_LEFT:	m_bLeftPressed	= false; bRet = true; break;
					case KEY_RIGHT:	m_bRightPressed	= false; bRet = true; break;
					case KEY_UP:		m_bUpPressed		= false; bRet = true; break; 
					case KEY_DOWN:	m_bDownPressed	= false; bRet = true; break;
					default:
						break;
				}
				break;
			case TBaseEvent::EKeyboardKeyDown:
				switch  (reinterpret_cast<TKeyboardEvent *>(pMessage)->m_iKeyId)
				{
					case KEY_LEFT:	m_bLeftPressed	= true; bRet = true; break;
					case KEY_RIGHT:	m_bRightPressed	= true; bRet = true; break;
					case KEY_UP:		m_bUpPressed		= true; bRet = true; break; 
					case KEY_DOWN:	m_bDownPressed	= true; bRet = true; break;
					default:
						break;
				}
				break;
		}
	}
	
	return bRet;
}

// *******************************************************************************
//
// *******************************************************************************
void CPlayerControllerComponent::activate(bool bActivate)
{
	CBaseComponent::activate(bActivate);
	if (getActivated())
		IEventsManager::get()->registerToEvents(this, 0);
	else
		IEventsManager::get()->unregisterToEvents(this);
}