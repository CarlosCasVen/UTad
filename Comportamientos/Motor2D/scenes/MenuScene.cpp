#include "../stdafx.h"
#include "MenuScene.h"
#include "../include/scene.h"

CMenuScene::CMenuScene(rapidjson::Document *info) : CBaseScene(EMenuScene, info)
{
}


Scene *CMenuScene::createRenderer()
{
	return NEW(Scene, ());
}