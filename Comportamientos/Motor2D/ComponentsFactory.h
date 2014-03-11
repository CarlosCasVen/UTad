#ifndef ___COMPONENTSFACTORY___
#define ___COMPONENTSFACTORY___

#include "IComponentsFactory.h"

class CComponentsFactory : public IComponentsFactory
{
public:
	virtual int  init();
	virtual void end ();

	virtual int	addClassesInfo(const rapidjson::Value *pInfo);

	virtual IComponent *	getComponent		(TType nType);
	virtual IComponent *	getComponent		(const rapidjson::Value *pInfo);
	virtual IComponent *	getComponent		(const char *pszClassName);
	virtual void					releaseComponent(IComponent *pEntity);

private:
	CComponentsFactory();
	~CComponentsFactory();

	static const int NUM_COMPONENTS_TYPES = EInvalid;

	TType				getComponentTypeByName	(const char *pszName);
	IComponent *getComponent						(IComponentsFactory::TType nType, const rapidjson::Value *pInfo);

	unsigned int generateComponentId();

	const rapidjson::Value *m_pInfo;

	unsigned int m_uComponentIdGen;

	friend class IComponentsFactory;
};

#endif