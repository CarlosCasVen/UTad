#ifndef ___EVENTMANAGER___
#define ___EVENTMANAGER___

#include "IEventsManager.h"
#include <vector>

struct TBaseEvent;
class IEntity;
class CEventsManager : public IEventsManager
{
	virtual int		init();
	virtual void	end ();

	virtual void	update();

	virtual int registerToEvents	(IEntity *pListener, int priority);
	virtual int unregisterToEvents(IEntity *pListener);

	virtual int registerToEvents	(IComponent *pListener, int priority);
	virtual int unregisterToEvents(IComponent *pListener);

private:

	void eventMouseButton	(int ibutton, int action);
	void eventKeyboard		(int iKey,		int action);

	void freeResources();

	int getListenerIdx(IEntity *		pListener);
	int getListenerIdx(IComponent *	pListener);

	struct TListenerInfo
	{
		IEntity			*m_pEntity;
		IComponent  *m_pComponent;
		int					 m_iPriority;
		TListenerInfo(IEntity	*pEntity, int	iPriority)
		{
			m_pComponent = NULL;
			m_pEntity		 = pEntity;
			iPriority		 = iPriority;
		}
		TListenerInfo(IComponent *pComponent, int	iPriority)
		{
			m_pComponent	= pComponent;
			m_pEntity			= NULL;
			m_iPriority		= m_iPriority;
		}
	};

	CEventsManager();
	~CEventsManager();

	std::vector<TListenerInfo *> m_aListeners;

	friend class IEventManager;
	friend void callbackMouseButton	(int ibutton, int action);
	friend void callbackKeyboard		(int iKey,		int action);

	std::vector<TBaseEvent *>m_aPendingEvents;

	friend class IEventsManager;
};

#endif