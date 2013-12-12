#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"


int	main(int	argc,	char*	argv[])	{	

	Screen::Instance().Open( 800, 600, false );
	glfwDisable(GLFW_MOUSE_CURSOR);

	Image* star = ResourceManager::Instance().LoadImage( "data/star.png" );

	star->SetMidHandle();

	Scene scene;
	Emitter* emitter = scene.CreateEmitter( star, true );
	Sprite* sprite = scene.CreateSprite( star );
	Affector affector1( 0, 0, 800, 100, true );
	Affector affector2( 0, 500, 800, 600, true );

	affector1.SetMinColor( 255, 0, 0 );
	affector1.SetMaxColor( 255, 0, 0 );
	affector1.SetVelX( 0, 0 );
	affector1.SetVelY( 0, 0 );
	affector1.SetVelAng( 0, 0 );

	affector2.SetMinColor( 0, 255, 255 );
	affector2.SetMaxColor( 0, 255, 255 );
	affector2.SetVelX( 0, 0 );
	affector2.SetVelY( 0, 0 );
	affector2.SetVelAng( 0, 0 );

	emitter->SetRate( 500, 1000 );
	emitter->SetVelocityX( -128, 128 );
	emitter->SetVelocityY( -128, 128 );
	emitter->SetAngularVelocity( 0, 360 );
	emitter->SetLifetime( 1, 5 );
	emitter->SetMinColor( 0, 0 ,0 );
	emitter->SetMaxColor( 255, 255, 255 );
	emitter->AddAffector( &affector1 );
	emitter->AddAffector( &affector2 );

	sprite->SetColor( 255, 200, 0 );

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