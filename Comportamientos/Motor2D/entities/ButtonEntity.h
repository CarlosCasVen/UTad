#ifndef ___BUTTONENTITY___
#define ___BUTTONENTITY___

#include "BaseEntity.h"
class ISound;
class CButtonEntity : public CBaseEntity
{
public:
	virtual int  addedToScene			(CBaseScene *pScene);
	virtual void removedFromScene	();

	virtual bool manageEvent(TBaseEvent *pMessage);

private:

	CButtonEntity(unsigned int uId, const rapidjson::Value *pInfo);

	ISound *m_pSound;

	friend class CEntitiesFactory;
};

#endif