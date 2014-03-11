#ifndef ___IENTITY___
#define ___IENTITY___

#include "IEntitiesFactory.h"

struct TBaseEvent;
class CBaseScene;
class IEntity
{
public:
	virtual int init()																= 0;

	virtual IEntitiesFactory::TType				getType()		= 0;

	virtual unsigned int								  getId()			= 0;

	virtual const char *									getName()		= 0;

	// Se a�de o se quita de la escena
	virtual int  addedToScene		(CBaseScene *pScene)	= 0;
	virtual void removedFromScene()										= 0;

	// Ejecuci�n
	virtual void update(float fDelta)									= 0;

	virtual int getPosX() = 0;
	virtual int getPosY() = 0;
	virtual int getPosZ() = 0;
	virtual void setPos(int x, int y, int z) = 0;

	// Recepci�n de mensages
	virtual bool manageEvent(TBaseEvent *pMessage)		= 0;
};

#endif