#ifndef __BASECOMPONENT____
#define __BASECOMPONENT____

#include "../IComponent.h"

class CBaseComponent : public IComponent
{
public:
	virtual int												init();

	virtual IComponentsFactory::TType getType	();
	virtual unsigned int							getId		();

	// Se añde o se quita de la escena
	virtual int												addedToEntity			(IEntity *pEntity);
	virtual void											removedFromEntity	();

	virtual void											activate					(bool bActivate);

	// Ejecución
	virtual void											update						(float fDelta);

	// Recepción de mensages
	virtual bool											manageEvent				(TBaseEvent *pMessage);

protected:
	CBaseComponent(IComponentsFactory::TType nType, unsigned int uId, const rapidjson::Value *pInfo);
	virtual ~CBaseComponent();

	IEntity *								getEntity		();
	bool										getActivated();
	const rapidjson::Value*	getInfo			();

private:
	IEntity * m_pEntity;
	bool			m_bActivated;
	IComponentsFactory::TType m_nType;
	unsigned int							m_uId;
	const rapidjson::Value*	  m_pInfo;

	friend class IComponentsFactory;
};

#endif