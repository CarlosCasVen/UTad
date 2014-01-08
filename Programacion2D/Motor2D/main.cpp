#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"


int	main(int	argc,	char*	argv[])	{	

	Screen::Instance().Open( 800, 600, false );

	glfwSetMousePos(400, 300);
	glfwDisable(GLFW_MOUSE_CURSOR);

	InputManager& input = InputManager::Instance();
	input.CreateVirtualAxis( "LeftRight", Key_D, Key_A );
	input.CreateVirtualAxis( "UpDown", Key_S, Key_W );


	Map* map = ResourceManager::Instance().LoadMap( "data/map.tmx" );
	MapScene scene ( map );	

	SkeletonSprite bones( "data/animation.xml" );
	bones.SetFPS( 32 );

	Sprite* alien = scene.CreateSprite( ResourceManager::Instance().LoadImage( "data/alienanim.png", 8, 1 ) );
	alien->SetFPS( 16 );
	alien->SetFrameRange( 0 , 8 );
	alien->SetScaleX( 6.0 );
	alien->SetScaleY( 6.0 );

	scene.GetCamera().SetBounds( 0, 0, scene.GetMap()->GetWidth(), scene.GetMap()->GetHeight() );
	scene.GetCamera().FollowSprite( alien );

	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	

		Renderer::Instance().Clear();

		bones.SetPosition( Screen::Instance().GetMouseX(), Screen::Instance().GetMouseY() );
		alien->MoveTo( alien->GetX() + 10 * input.GetVirtualAxis( "LeftRight" ), alien->GetY() + 10 * input.GetVirtualAxis( "UpDown" ), 100 );

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
		bones.Update( Screen::Instance().ElapsedTime() );
		bones.Render();
		input.Update();
		Screen::Instance().Refresh();
	}

	return	0;	
}

