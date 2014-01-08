#include "../include/isometricScene.h"



IsometricScene::IsometricScene(IsometricMap* map, Image* imageBack = NULL, Image* imageFront = NULL) : MapScene( ( Map* )map, imageBack, imageFront )
{
	map->GenerateLayerSprites( this );
}


IsometricSprite* IsometricScene::CreateSprite(Image* image, Layer layer = LAYER_BACK)
{
	IsometricSprite* sprite = new IsometricSprite( image );
	AddSprite( sprite, layer );
}


void IsometricScene::Update(double elapsed, Map* map = NULL)
{
	Scene::Update( elapsed, map );
	
	for( int i = 0; i < LAYER_COUNT; i++ )
	{
		GetSprites( (Layer) i ).Sort( CompareSprites );
	}
	
}


bool IsometricScene::CompareSprites(Sprite*& first, Sprite*& second)
{
	return first->GetScreenY() < second->GetScreenY();
}