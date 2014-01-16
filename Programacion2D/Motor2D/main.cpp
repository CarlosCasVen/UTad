#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"

const unsigned int LEFT = 0;
const unsigned int RIGHT = 40;
const unsigned int UP = 24;
const unsigned int DOWN = 56;
const unsigned int NUM_FRAMES = 3;

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
	ninja->SetCollision( Sprite::COLLISION_RECT );

	scene.GetCamera().FollowSprite( ninja );

	double posX = 0, posY = 0;
	double tileX = 0, tileY = 0;
	int firstColId = 3;

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	
		
		Renderer::Instance().Clear();
		if( !ninja->IsMoving() )
		{
			posX = ninja->GetX();
			posY = ninja->GetY();	
		

			if( input.IsVirtualButtonPressed( "Left" ) )
			{
				posX -= map->GetTileWidth();
				ninja->SetFrameRange( LEFT, LEFT + NUM_FRAMES );
			}
			else if( input.IsVirtualButtonPressed( "Right" ) )
			{
				posX += map->GetTileWidth();
				ninja->SetFrameRange( RIGHT, RIGHT + NUM_FRAMES );
			}
			else if( input.IsVirtualButtonPressed( "Up" ) )
			{
				posY -= map->GetTileHeight();
				ninja->SetFrameRange( UP, UP + NUM_FRAMES );
			}
			else if( input.IsVirtualButtonPressed( "Down" ) )
			{
				posY += map->GetTileHeight();
				ninja->SetFrameRange( DOWN, DOWN + NUM_FRAMES );
			}
		}

		tileX = posX / map->GetTileWidth();
        tileY = posY / map->GetTileHeight();

		if( map->GetTileId( tileX, tileY) < firstColId  &&  map->GetLayerId( tileX, tileY ) < firstColId )
        {
			ninja->MoveTo( posX, posY, 100, 100 );
		}

		ninja->IsMoving() ? ninja->SetFPS( 10 ) : ninja->SetFPS( 0 );

		scene.Update( Screen::Instance().ElapsedTime() );
		scene.Render();
		input.Update();
		Screen::Instance().Refresh();
	}

	return	0;	
}

