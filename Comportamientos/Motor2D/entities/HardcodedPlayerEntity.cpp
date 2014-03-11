#include "../stdafx.h"
#include "HardcodedPlayerEntity.h"
#include "../IComponentsFactory.h"

// ***********************************************************************************
//
// ***********************************************************************************
CHardcodedPlayerEntity::CHardcodedPlayerEntity(unsigned int uId, const rapidjson::Value *pInfo) : 
	CComponentsEntity(IEntitiesFactory::EHardcodedPlayer, uId, pInfo)
{
}

// ***********************************************************************************
//
// ***********************************************************************************
int CHardcodedPlayerEntity::init()
{
	bool bRet = CComponentsEntity::init();
	addComponent(IComponentsFactory::get()->getComponent(IComponentsFactory::EPlayerController));
	return bRet;
}