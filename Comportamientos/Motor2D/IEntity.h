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

	// Se añde o se quita de la escena
	virtual int  addedToScene		(CBaseScene *pScene)	= 0;
	virtual void removedFromScene()										= 0;

	// Ejecución
	virtual void update(float fDelta)									= 0;

	virtual int getPosX() = 0;
	virtual int getPosY() = 0;
	virtual int getPosZ() = 0;
	virtual void setPos(int x, int y, int z) = 0;

	// Recepción de mensages
	virtual bool manageEvent(TBaseEvent *pMessage)		= 0;
};

#endif