#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"


int	main(int	argc,	char*	argv[])	{	
	Screen::Instance().Refresh();
	Screen::Instance().Open( 800, 600, false );

	glfwSetMousePos(400, 300);
	//glfwDisable(GLFW_MOUSE_CURSOR);
	
	InputManager& input = InputManager::Instance();
	input.CreateVirtualButton( "Left", Key_A );
	input.CreateVirtualButton( "Right", Key_D );
	input.CreateVirtualButton( "Up", Key_W );
	input.CreateVirtualButton( "Down", Key_S );
	
	IsometricMap* map = ResourceManager::Instance().LoadIsometricMap( "data/isometric.tmx" );
	IsometricScene scene ( map );	

	Image* ninjaImage = ResourceManager::Instance().LoadImage( "data/isoplayer.png", 8, 8 );
	ninjaImage->SetHandle( ninjaImage->GetWidth() / 2, ninjaImage->GetHeight() );
	IsometricSprite* ninja = scene.CreateSprite( ninjaImage );
	ninja->SetPosition( map->GetTileWidth() * 1.5, map->GetTileHeight() * 1.5 );
	ninja->SetCollision( Sprite::COLLISION_PIXEL );

	scene.GetCamera().FollowSprite( ninja );

	double posX = 0, posY = 0;

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	
	
		Renderer::Instance().Clear();
		posX = ninja->GetX();
		posY = ninja->GetY();	

		if( input.IsVirtualButtonPressed( "Left" ) )
		{
			ninja->SetCurrentFrame( 0 );
			posX -= map->GetTileWidth();
		}
		if( input.IsVirtualButtonPressed( "Right" ) )
		{
			ninja->SetCurrentFrame( 40 );
			posX += map->GetTileWidth();
		}
		if( input.IsVirtualButtonPressed( "Up" ) )
		{
			ninja->SetCurrentFrame( 24 );
			posY -= map->GetTileHeight();
		}
		if( input.IsVirtualButtonPressed( "Down" ) )
		{
			ninja->SetCurrentFrame( 56 );
			posY += map->GetTileHeight();
		}
		
		if( ninja->DidCollide() )
		{
			posX = ninja->GetX();
			posY = ninja->GetY();
		}

		ninja->SetCurrentFrame( ninja->GetCurrentFrame() );
		ninja->MoveTo( posX, posY, 10 );

		scene.Update( Screen::Instance().ElapsedTime(), map );
		scene.Render();
		input.Update();
		Screen::Instance().Refresh();
	}

	return	0;	
}

