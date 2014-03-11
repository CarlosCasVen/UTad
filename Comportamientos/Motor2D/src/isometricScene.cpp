#include "../include/isometricScene.h"
#include "../include/isometricMap.h"



IsometricScene::IsometricScene(IsometricMap* map, Image* imageBack, Image* imageFront ) : MapScene( ( Map* )map, imageBack, imageFront )
{
	map->GenerateLayerSprites( this );
}


IsometricSprite* IsometricScene::CreateSprite(Image* image, Layer layer )
{
	IsometricSprite* sprite = new IsometricSprite( image );
	AddSprite( sprite, layer );

	return sprite;
}


void IsometricScene::Update(double elapsed, Map* map )
{
	Scene::Update( elapsed, map );

	for( int i = 0; i < LAYER_COUNT; i++ )
	{
		GetSprites( (Layer) i ).Sort( CompareSprites );
	}
	
}


bool IsometricScene::CompareSprites(Sprite*& first, Sprite*& second)
{
	return first->GetScreenY() <= second->GetScreenY();
}