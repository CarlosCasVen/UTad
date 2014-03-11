#ifndef __MENUSCENE__

#include "BaseScene.h"

// *******************************************************************************************
// Base clase de un escena de la lógica
// *******************************************************************************************
class CMenuScene : public CBaseScene
{
public:
	CMenuScene(rapidjson::Document *pInfo);

private:
	virtual Scene *createRenderer();
};

#endif