/*#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"


int	main(int	argc,	char*	argv[])	{	

	Screen::Instance().Open( 800, 600, false );

	glfwSetMousePos(400, 300);
	//glfwDisable(GLFW_MOUSE_CURSOR);

	InputManager& input = InputManager::Instance();
	input.CreateVirtualAxis( "LeftRight", Key_D, Key_A );
	input.CreateVirtualAxis( "UpDown", Key_S, Key_W );

	Map* map = ResourceManager::Instance().LoadMap( "data/map.tmx" );
	MapScene scene ( map );	

	Sprite* alien = scene.CreateSprite( ResourceManager::Instance().LoadImage( "data/alien.png" ) );
	alien->SetCollisionPixelData( &CollisionPixelData( "data/aliencol.png" ) );
	alien->SetCollision( Sprite::COLLISION_PIXEL );
	//Sprite* alien = scene.CreateSprite( ResourceManager::Instance().LoadImage( "data/alienanim.png", 8, 1 ) );
	//alien->SetFPS( 16 );
	//alien->SetFrameRange( 0 , 8 );
	//alien->SetScaleX( 6.0 );
	//alien->SetScaleY( 6.0 );

	scene.GetCamera().SetBounds( 0, 0, scene.GetMap()->GetWidth(), scene.GetMap()->GetHeight() );
	scene.GetCamera().FollowSprite( alien );

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	

		Renderer::Instance().Clear();
		
	//	Screen::Instance().SetTitle( String::FromFloat( input.GetVirtualAxis( "LeftRight" ) ) + "/" + String::FromFloat( input.GetVirtualAxis( "UpDown" ) ) );

		alien->SetPosition( alien->GetX() + 10 * input.GetVirtualAxis( "LeftRight" ), alien->GetY() + 10 * input.GetVirtualAxis( "UpDown" ) );
		
		if( Screen::Instance().KeyPressed( GLFW_KEY_RIGHT ) )
			alien->MoveTo( alien->GetX() + 500, alien->GetY() + 500, 15 );
		if( Screen::Instance().KeyPressed( GLFW_KEY_DOWN ) )
			alien->RotateTo( -60, 15 );

		if( alien->DidCollide() )
		{
			alien->SetColor( 255,0,0);
		}
		else
		{
			alien->SetColor( 255,255,255);
		}

		scene.Update( Screen::Instance().ElapsedTime() );
		scene.Render();
		input.Update();
		Screen::Instance().Refresh();
	}

	return	0;	
}

*/




/*	
	d = 10 * abs (cos( Time ( 0 ) )) ;
	
	x = sin( Time( 0 ) ) + cos( time( 0 ) );
	y = 300 + d sin( time( 0 ) );
	*/



