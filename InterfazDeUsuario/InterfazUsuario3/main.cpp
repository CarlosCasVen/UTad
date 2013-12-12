#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"


int	main(int	argc,	char*	argv[])	{	

	Screen::Instance().Open( 800, 600, true );

	//glfwDisable(GLFW_MOUSE_CURSOR);

	Image* star = ResourceManager::Instance().LoadImage( "data/star.png" );

	Scene scene;
	Sprite* sprite = scene.CreateSprite( star );
	Emitter* emitter = scene.CreateEmitter( star, true );
	
	emitter->SetRate( 500, 1000 );
	emitter->SetVelocityX( -128, 128 );
	emitter->SetVelocityY( -128, 128 );
	emitter->SetAngularVelocity( 0, 360 );
	emitter->SetLifetime( 1, 8 );
	emitter->SetMinColor( 0, 0 ,0 );
	emitter->SetMaxColor( 255, 255, 255 );



	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	

		Renderer::Instance().Clear();

		if( Screen::Instance().MouseButtonPressed( GLFW_MOUSE_BUTTON_1 ) )
		{
			emitter->Start();
		}
		else
		{
			emitter->Stop();
		}

		emitter->SetX( Screen::Instance().GetMouseX() );
		emitter->SetY( Screen::Instance().GetMouseY() );
		sprite->SetX( Screen::Instance().GetMouseX() );
		sprite->SetY( Screen::Instance().GetMouseY() );
		
		scene.Update( Screen::Instance().ElapsedTime() );
		scene.Render();
		
		Screen::Instance().Refresh();
	}

	return	0;	
}