#ifndef ____ICOMPONENT____
#define ____ICOMPONENT____

struct TBaseEvent;

#include "IComponentsFactory.h"

class IEntity;

class IComponent 
{
public:
	virtual int												init()		 = 0;

	virtual IComponentsFactory::TType getType	() = 0;

	virtual unsigned int							getId()		 = 0;

		// Se a�de o se quita de la escena
	virtual int												addedToEntity			(IEntity *pEntity)	= 0;
	virtual void											removedFromEntity	()									= 0;

	virtual void											activate					(bool bActivate)		= 0;

	// Ejecuci�n
	virtual void											update						(float fDelta)			= 0;

	// Recepci�n de mensages
	virtual bool											manageEvent	(TBaseEvent *pMessage)		= 0;
};

#endif