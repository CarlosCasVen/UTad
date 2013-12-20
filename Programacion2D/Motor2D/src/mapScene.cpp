#include "../include/mapScene.h"
#include "../include/map.h"



MapScene::MapScene(Map* map, Image* imageBack = 0, Image* imageFront = 0) : ParallaxScene( imageBack, imageFront )
{
	this->map = map;
}
	

	

void MapScene::Update(double elapsed)
{
	ParallaxScene::Update( elapsed, map );
}


void MapScene::RenderAfterBackground() const
{
	map->Render();
}