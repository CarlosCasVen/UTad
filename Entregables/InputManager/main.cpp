/*#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "include/u-gine.h"


int	main(int	argc,	char*	argv[])	{	

	Screen::Instance().Open( 800, 600, false );
	Screen::Instance().Refresh();
	glfwSetMousePos(400, 300);
	glfwDisable(GLFW_MOUSE_CURSOR);

	Image* star = ResourceManager::Instance().LoadImage( "data/star.png" );

	star->SetMidHandle();

	Scene scene;

	InputManager manager = InputManager::Instance();
	manager.CreateVirtualButton( "Change cursor", eInputCode::Mouse_Button1 );

	///////////////////////
	Image* ballImage = ResourceManager::Instance().LoadImage("data/ball.png");
	ballImage->SetMidHandle();

	Sprite* ball = scene.CreateSprite( ballImage );
	ball->SetPosition( 100, 100 );
	ball->SetCollision( Sprite::CollisionMode::COLLISION_CIRCLE );
	ball->SetRadius( ResourceManager::Instance().LoadImage("data/ball.png")->GetWidth() / 2);

	Sprite* box = scene.CreateSprite( ResourceManager::Instance().LoadImage("data/box.jpg"));
	
	box->SetCollision( Sprite::CollisionMode::COLLISION_RECT );
	box->SetPosition( 700, 500 );
	
	Sprite* alien = scene.CreateSprite( ResourceManager::Instance().LoadImage("data/alien.png"));
	alien->SetPosition( 100, 500 );
	alien->SetCollisionPixelData( ResourceManager::Instance().LoadCollisionPixelData( "data/aliencol.png") );
	alien->SetCollision( Sprite::CollisionMode::COLLISION_PIXEL );

	Image* circle = ResourceManager::Instance().LoadImage( "data/circle.png" );
	circle->SetMidHandle();
	
	Image* rect = ResourceManager::Instance().LoadImage( "data/rect.png" );
	rect->SetMidHandle();

	Image* alienImage =  ResourceManager::Instance().LoadImage( "data/alien.png" );
	alienImage->SetMidHandle();

	Sprite* cursor = scene.CreateSprite( alienImage );
	cursor->SetRadius( ResourceManager::Instance().LoadImage( "data/circle.png" )->GetWidth() / 2 );
	cursor->SetCollisionPixelData( ResourceManager::Instance().LoadCollisionPixelData( "data/aliencol.png") );
	cursor->SetCollision( Sprite::CollisionMode::COLLISION_PIXEL );
	
	unsigned int nCliks = 0;


	while(Screen::Instance().IsOpened()	&& !Screen::Instance().KeyPressed( GLFW_KEY_ESC ))
	{	

		Renderer::Instance().Clear();



		if( manager.IsVirtualButtonDown("Change cursor") )
		{
			int x = 1;
			nCliks = ++nCliks % 3;
			switch( nCliks )
			{
				case 0:
					{
						cursor->SetImage( circle );
						cursor->SetCollision( Sprite::CollisionMode::COLLISION_CIRCLE );
						break;																										   
					}																												   
				case 1:																												   
					{																												   
						cursor->SetImage( rect );
						cursor->SetCollision( Sprite::CollisionMode::COLLISION_RECT );
						break;																											   
					}																												   
				case 2:																												   
					{																												   
						cursor->SetImage( alienImage );
						cursor->SetCollisionPixelData( ResourceManager::Instance().LoadCollisionPixelData( "data/aliencol.png") );
						cursor->SetCollision( Sprite::CollisionMode::COLLISION_PIXEL );
						break;	
					}
			}

			cursor->SetColor(  cursor->GetRed(), cursor->GetGreen(), cursor->GetBlue(), 255 );
		}
		

	
		if( cursor->DidCollide() )
		{
			cursor->SetColor( 255, 0, 0 );
		}
		else
		{
			cursor->SetColor( 255, 255, 255 );
		}


		if( alien->DidCollide() )
		{
			alien->SetColor( 255, 0, 0 );
		}
		else if( box->DidCollide() )
		{
			box->SetColor( 255, 0, 0 );
		}
		else if ( ball->DidCollide() )
		{
			ball->SetColor( 255, 0, 0 );
		}
		else
		{
			alien->SetColor( 255, 255, 255 );
			ball->SetColor( 255, 255, 255 );
			box->SetColor( 255, 255, 255 );
		}
		
		cursor->SetPosition( Screen::Instance().GetMouseX(), Screen::Instance().GetMouseY() ); 

		manager.Update();
		scene.Update( Screen::Instance().ElapsedTime() );
		scene.Render();

		Screen::Instance().Refresh();
	}

	return	0;	
}






	
	d = 10 * abs (cos( Time ( 0 ) )) ;
	
	x = sin( Time( 0 ) ) + cos( time( 0 ) );
	y = 300 + d sin( time( 0 ) );




*/