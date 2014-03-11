#ifndef ___HARDCODEDPLAYER___
#define ___HARDCODEDPLAYER___

#include "ComponentsEntity.h"

class CHardcodedPlayerEntity : public CComponentsEntity
{
public:
	virtual int init();

private:
	CHardcodedPlayerEntity(unsigned int uId, const rapidjson::Value *pInfo);

	friend class CEntitiesFactory;
};

#endif