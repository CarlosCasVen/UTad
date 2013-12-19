#include "../include/parallaxScene.h"
#include "../include/renderer.h"
#include "../include/image.h"
#include "../include/screen.h"

ParallaxScene::ParallaxScene(Image* imageBack, Image* imageFront ) : Scene( imageBack ), backLayer( imageBack ), frontLayer( imageFront )
{
	backX = backY = 0.0;
	frontX = frontY = 0.0;
	SetRelativeBackSpeed( 0.0, 0.0 );
	SetRelativeFrontSpeed( 0.0, 0.0 );
	SetAutoBackSpeed( 0.0, 0.0 );
	SetAutoFrontSpeed( 0.0, 0.0 );
}


void ParallaxScene::Update(double elapsed, Map* map )
{
	Scene::Update( elapsed, map );

	if( backLayer )
	{
		backX += autoBackSpeedX * relBackSpeedX * elapsed;
		backY += autoBackSpeedY * relBackSpeedY * elapsed;
	}

	if( frontLayer )
	{
		frontX += autoFrontSpeedX * relFrontSpeedX * elapsed;
		frontY += autoFrontSpeedY * relFrontSpeedY * elapsed;
	}

}


void ParallaxScene::RenderBackground() const
{	
	if( backLayer )
	{
		Renderer::Instance().DrawTiledImage( backLayer, 0, 0, Screen::Instance().GetWidth(), Screen::Instance().GetHeight(), backX, backY );
	}

	if( frontLayer )
	{
		Renderer::Instance().DrawTiledImage( frontLayer, 0, 0, Screen::Instance().GetWidth(), Screen::Instance().GetHeight(), frontX, frontY );
	}
}
