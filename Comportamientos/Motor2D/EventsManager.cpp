#include "stdafx.h"
#include "EventsManager.h"
#include "lib/glfw.h"
#include "events/MouseEvents.h"
#include "events/KeyboardEvents.h"
#include "IEntity.h"
#include "IComponent.h"

CEventsManager *g_pEM = NULL;

void callbackMouseButton(int ibutton, int iAction)
{
	if (g_pEM)
		g_pEM->eventMouseButton(ibutton, iAction);
}

void callbackKeyboard(int ibutton, int iAction)
{
	if (g_pEM)
		g_pEM->eventKeyboard(ibutton, iAction);
}

// *******************************************************************************
//
// *******************************************************************************
IEventsManager *IEventsManager::get()
{
	if (!g_pEM)
		g_pEM = NEW(CEventsManager, ());

	return g_pEM;
}

// *******************************************************************************
//
// *******************************************************************************
int	CEventsManager::init()
{
	glfwSetMouseButtonCallback(callbackMouseButton);
	glfwSetKeyCallback				(callbackKeyboard);
	return RET_OK;
}

// *******************************************************************************
//
// *******************************************************************************
void CEventsManager::end()
{
	SAFE_DELETE(g_pEM);
}

// *******************************************************************************
//
// *******************************************************************************
CEventsManager::CEventsManager()
{
}
CEventsManager::~CEventsManager()
{
	freeResources();
}

// *******************************************************************************
//
// *******************************************************************************
int CEventsManager::registerToEvents(IEntity *pListener, int priority)
{
	if (getListenerIdx(pListener) == -1)
	{
		TListenerInfo *pListenerInfo = NEW(TListenerInfo, (pListener, priority));
		// FIXME: insertar ordenado por prioridad.
		m_aListeners.push_back(pListenerInfo);
	}
	return RET_OK;
}

// *******************************************************************************
//
// *******************************************************************************
int CEventsManager::unregisterToEvents(IEntity *pListener)
{
	int iIdx = getListenerIdx(pListener);
	if (iIdx != -1)
	{
		DEL(m_aListeners[iIdx]);
		m_aListeners.erase(m_aListeners.begin() + iIdx);
	}
	return RET_OK;
}

// *******************************************************************************
//
// *******************************************************************************
int CEventsManager::registerToEvents(IComponent *pListener, int priority)
{
	if (getListenerIdx(pListener) == -1)
	{
		TListenerInfo *pListenerInfo = NEW(TListenerInfo, (pListener, priority));
		// FIXME: insertar ordenado por prioridad.
		m_aListeners.push_back(pListenerInfo);
	}
	return RET_OK;
}

// *******************************************************************************
//
// *******************************************************************************
int CEventsManager::unregisterToEvents(IComponent *pListener)
{
	int iIdx = getListenerIdx(pListener);
	if (iIdx != -1)
	{
		DEL(m_aListeners[iIdx]);
		m_aListeners.erase(m_aListeners.begin() + iIdx);
	}
	return RET_OK;
}

// *******************************************************************************
//
// *******************************************************************************
void CEventsManager::update()
{
	 while (!m_aPendingEvents.empty())
  {
    TBaseEvent *pEvent = m_aPendingEvents.back();

		bool					bProcessed	= false;
		unsigned int	i						= 0;
		while (!bProcessed && (i < m_aListeners.size()))
		{
			if (m_aListeners[i]->m_pEntity)
				bProcessed = m_aListeners[i]->m_pEntity->manageEvent(pEvent);
			else
				if (m_aListeners[i]->m_pComponent)
					bProcessed = m_aListeners[i]->m_pComponent->manageEvent(pEvent);
			i++;
		}
		DEL(pEvent);
    m_aPendingEvents.pop_back();
  }

}

// *******************************************************************************
//
// *******************************************************************************
void CEventsManager::freeResources()
{
	for (unsigned int i = 0; i < m_aListeners.size(); i++)
		DEL(m_aListeners[i]);
}

// *******************************************************************************
//
// *******************************************************************************
int CEventsManager::getListenerIdx(IEntity *pListener)
{
	int iRet = -1;
	unsigned int i = 0;
	while ((iRet == -1) && (i < m_aListeners.size()))
	{
		if (m_aListeners[i]->m_pEntity == pListener)
			iRet = i;
		else
			i++;
	}
	return iRet;
}

// *******************************************************************************
//
// *******************************************************************************
int CEventsManager::getListenerIdx(IComponent *pListener)
{
	int iRet = -1;
	unsigned int i = 0;
	while ((iRet == -1) && (i < m_aListeners.size()))
	{
		if (m_aListeners[i]->m_pComponent == pListener)
			iRet = i;
		else
			i++;
	}
	return iRet;
}

// *******************************************************************************
//
// *******************************************************************************
void CEventsManager::eventMouseButton(int ibutton, int action)
{
	int x, y;
	glfwGetMousePos(&x, &y);
	m_aPendingEvents.push_back(NEW(TMouseEvent, (TBaseEvent::EMouseLeftButtomDown, static_cast<float>(x), static_cast<float>(y))));
}

// *******************************************************************************
//
// *******************************************************************************
void CEventsManager::eventKeyboard(int iKey, int action)
{
	if (action == 1)
		m_aPendingEvents.push_back(NEW(TKeyboardEvent, (TBaseEvent::EKeyboardKeyDown, iKey)));
	else
		m_aPendingEvents.push_back(NEW(TKeyboardEvent, (TBaseEvent::EKeyboardKeyUp, iKey)));
}