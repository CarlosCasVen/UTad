#ifndef ___COMPONENTESENTITY___
#define ___COMPONENTESENTITY___

#include "BaseEntity.h"
#include <vector>

class IComponent;
class CComponentsEntity : public CBaseEntity
{
public:
	virtual int  addedToScene			(CBaseScene *pScene);
	virtual void removedFromScene	();
	virtual bool manageEvent			(TBaseEvent *pMessage);

	// Ejecución
	virtual void update(float fDelta);

protected:
	int addComponent(IComponent *pComponent);

	CComponentsEntity(IEntitiesFactory::TType nType, unsigned int uId, const rapidjson::Value *pInfo);
	~CComponentsEntity();

private:
	CComponentsEntity(unsigned int uId, const rapidjson::Value *pInfo);
	
	std::vector<IComponent *> m_vComponents;

	friend class CEntitiesFactory;
};

#endif