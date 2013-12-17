#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"


int	main(int	argc,	char*	argv[])	{	

	Screen::Instance().Open( 800, 600, false );
	glfwSetMousePos(400, 300);
	glfwDisable(GLFW_MOUSE_CURSOR);

	Image* star = ResourceManager::Instance().LoadImage( "data/star.png" );

	star->SetMidHandle();

	Scene scene;
	Emitter* emitter = scene.CreateEmitter( star, true );
	Sprite* sprite = scene.CreateSprite( star );
	Affector affector1( 0, 0, 400, 600 );
	Affector affector2( 400, 0, 800, 600 );


	affector1.SetFlag( COLOR_ACTIVE | VELANG_ACTIVE );
	affector1.SetMinColor( 0, 0, 0 );
	affector1.SetMaxColor( 255, 255, 0 );
	affector1.SetVelX( 0, 0 );
	affector1.SetVelY( 0, 0 );
	affector1.SetVelAng( 0, 360 );

	affector2.SetFlag( COLOR_ACTIVE | VELANG_ACTIVE );
	affector2.SetMinColor( 0, 0, 0 );
	affector2.SetMaxColor( 0, 255, 255 );
	affector2.SetVelX( 0, 0 );
	affector2.SetVelY( 0, 0 );
	affector2.SetVelAng( 360, 720 );
	
	emitter->SetRate( 500, 1000 );
	emitter->SetVelocityX( -128, 128 );
	emitter->SetVelocityY( -128, 128 );
	emitter->SetAngularVelocity( 0, 360 );
	emitter->SetLifetime( 1, 2 );
	emitter->SetMinColor( 0, 0 ,0 );
	emitter->SetMaxColor( 255, 255, 255 );
	emitter->AddAffector( &affector1 );
	emitter->AddAffector( &affector2 );

	sprite->SetColor( 255, 200, 0 );




	///////////////////////

/*	Sprite* ball = scene.CreateSprite( ResourceManager::Instance().LoadImage("data/ball.png"));
	ball->SetPosition( 100, 100 );
	Sprite* box = scene.CreateSprite( ResourceManager::Instance().LoadImage("data/box.jpg"));
	box->SetPosition( 700, 500 );
	Sprite* alien = scene.CreateSprite( ResourceManager::Instance().LoadImage("data/alien.png"));
	alien->SetPosition( 100, 500 );

	Image* cursorImage[3] = { ResourceManager::Instance().LoadImage("data/circle.png"), ResourceManager::Instance().LoadImage("data/rect.png") 
	, ResourceManager::Instance().LoadImage("data/alien.png")};
	Sprite* cursor = scene.CreateSprite( cursorImage[0] );
	unsigned int nCliks = 0;*/
	////////////////////

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

/*		if( Screen::Instance().MouseButtonPressed( GLFW_MOUSE_BUTTON_2 ) )
		{
			nCliks++;
			cursor->SetImage( cursorImage[ nCliks % 3 ] );
		}
		cursor->SetPosition( Screen::Instance().GetMouseX(), Screen::Instance().GetMouseY() ); 
*/

		scene.Update( Screen::Instance().ElapsedTime() );
		scene.Render();

		Screen::Instance().Refresh();
	}

	return	0;	
}



/*


	
	d = 10 * abs (cos( Time ( 0 ) )) ;
	
	x = sin( Time( 0 ) ) + cos( time( 0 ) );
	y = 300 + d sin( time( 0 ) );




*/