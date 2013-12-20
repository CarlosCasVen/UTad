#include "../include/mapScene.h"
#include "../include/map.h"



MapScene::MapScene(Map* map, Image* imageBack, Image* imageFront) : ParallaxScene( imageBack, imageFront )
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