#include "../include/parallaxScene.h"
#include "../include/renderer.h"
#include "../include/image.h"
#include "../include/screen.h"

ParallaxScene::ParallaxScene(Image* imageBack, Image* imageFront ) : backLayer( imageBack ), frontLayer( imageFront )
{
	backX = backY = 0.0;
	frontX = frontY = 0.0;
	SetRelativeBackSpeed( 1.0, 1.0 );
	SetRelativeFrontSpeed( 1.0, 1.0 );
	SetAutoBackSpeed( 0.0, 0.0 );
	SetAutoFrontSpeed( 0.0, 0.0 );
}


void ParallaxScene::Update(double elapsed, Map* map )
{
	Scene::Update( elapsed, map );

	if( backLayer )
	{
		backX -= autoBackSpeedX * elapsed;
		backY -= autoBackSpeedY * elapsed;
	}

	if( frontLayer )
	{
		frontX -= autoFrontSpeedX * elapsed;
		frontY -= autoFrontSpeedY * elapsed;
	}

}


void ParallaxScene::RenderBackground() const
{	
	if( backLayer )
	{
		Renderer::Instance().DrawTiledImage( backLayer, 0, 0, Screen::Instance().GetWidth(), Screen::Instance().GetHeight(), backX + Scene::GetCamera().GetX() * relBackSpeedX, backY + Scene::GetCamera().GetY() * relBackSpeedY );
	}

	if( frontLayer )
	{
		Renderer::Instance().DrawTiledImage( frontLayer, 0, 0, Screen::Instance().GetWidth(), Screen::Instance().GetHeight(),  frontX + Scene::GetCamera().GetX() * relFrontSpeedX, frontY + Scene::GetCamera().GetY() * relFrontSpeedY );
	}
}
