#ifndef ___ENTITIESFACTORY___
#define ___ENTITIESFACTORY___

#include "IEntitiesFactory.h"
#include "Utils/rapidjson/document.h"

class CEntitiesFactory : public IEntitiesFactory
{
public:

	virtual int  init();
	virtual void end ();

	virtual int				addClassesInfo(const rapidjson::Value *pInfo);

	virtual IEntity *	getEntity			(IEntitiesFactory::TType nType);
	virtual IEntity *	getEntity			(const rapidjson::Value *pInfo);
	virtual IEntity *	getEntity			(const char *pszClassName);;
	virtual void			releaseEntity (IEntity *pEntity);

private:

	CEntitiesFactory();
	~CEntitiesFactory();

	unsigned int			generateEntityId();

	static const int NUM_ENTITY_TYPES = EInvalid;

	TType				getEntityTypeByName	(const char *pszName);
	IEntity *   getEntity						(IEntitiesFactory::TType nType, const rapidjson::Value *pInfo);

	const rapidjson::Value *m_pEntitiesClassesInfo;

	struct TEntityInfo
	{
		TType				nType;
		const char *pszTypeName;
	};
	static TEntityInfo s_aEntitiesInfo[];

	unsigned int m_uEntityIdGen;

	friend class IEntitiesFactory;
};

#endif