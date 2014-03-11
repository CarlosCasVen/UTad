#ifndef ___EVENETMANAGER___
#define ___EVENETMANAGER___

struct TBaseEvent;
class IEntity;
class IComponent;
class IEventsManager
{
public:

	static IEventsManager *get();

	virtual int		init() = 0;
	virtual void	end () = 0;

	virtual void	update() = 0;

	virtual int registerToEvents	(IEntity *pListener, int priority)	= 0;
	virtual int unregisterToEvents(IEntity *pListener)								= 0;

	virtual int registerToEvents	(IComponent *pListener, int priority)	= 0;
	virtual int unregisterToEvents(IComponent *pListener)								= 0;
};

#endif
